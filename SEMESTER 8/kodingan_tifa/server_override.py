import cv2
import asyncio
import websockets
import base64
import numpy as np
from ultralytics import YOLO
import json
import time
import os

# --- KONFIGURASI SERVER ---    
PORT = 8000
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
TABLE_MODEL_PATH = os.path.join(BASE_DIR, 'bestnano.pt')
OBJECT_MODEL_PATH = os.path.join(BASE_DIR, 'yolov8n.pt')
CONF_THRESHOLD_TABLE = 0.35
CONF_THRESHOLD_OBJ = 0.25

DIRTY_INDICATORS = [39, 41, 42, 43, 44, 45, 67, 73]

print("[INFO] Memuat Model AI...")
try:
    table_model = YOLO(TABLE_MODEL_PATH)
    obj_model = YOLO(OBJECT_MODEL_PATH)
    print("[SUCCESS] Model siap.")
except Exception as e:
    print(f"[CRITICAL ERROR] Gagal memuat model YOLO: {e}")
    exit()

async def tifa_override_handler(websocket):
    print(f"\n[INFO] Raspberry Pi Terhubung: {websocket.remote_address}")

    frame_count = 0
    try:
        async for message in websocket:
            start_time = time.time()

            payload = json.loads(message)
            img_b64 = payload.get("image", "")
            robot_id = payload.get("robot_id", "UNKNOWN")

            if not img_b64:
                continue

            # --- PERBAIKAN: Penanganan Decode yang Lebih Aman ---
            try:
                img_bytes = base64.b64decode(img_b64)
                nparr = np.frombuffer(img_bytes, np.uint8)
                frame = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
            except Exception as e:
                print(f"[WARNING] Gagal menerjemahkan gambar: {e}")
                continue

            if frame is None:
                print("[WARNING] Gambar diterima tapi kosong (None).")
                continue

            frame_count += 1
            if frame_count % 10 == 0:
                print(f"[OK] Menerima Frame ke-{frame_count} dengan ukuran: {frame.shape}")

            # --- PROSES DETEKSI AI ---
            table_results = table_model.predict(frame, conf=CONF_THRESHOLD_TABLE, verbose=False)
            obj_results = obj_model.predict(frame, conf=CONF_THRESHOLD_OBJ, classes=DIRTY_INDICATORS, verbose=False)
            detected_objects = obj_results[0].boxes

            is_dirty_final = False

            for result in table_results:
                for box in result.boxes:
                    x1, y1, x2, y2 = map(int, box.xyxy[0])
                    cls = int(box.cls[0])
                    conf = float(box.conf[0])
                    status_name = table_model.names[cls]

                    color = (0, 255, 0) # Hijau
                    label = status_name

                    if status_name == 'meja_bersih':
                        found_trash = False
                        for obj in detected_objects:
                            ox1, oy1, ox2, oy2 = map(int, obj.xyxy[0])
                            ocx, ocy = (ox1 + ox2) // 2, (oy1 + oy2) // 2
                            if x1 < ocx < x2 and y1 < ocy < y2:
                                found_trash = True
                                break

                        if found_trash:
                            label = "meja_kotor (OVERRIDDEN)"
                            color = (0, 0, 255) # Merah
                            is_dirty_final = True
                    elif 'kotor' in status_name:
                        color = (0, 0, 255)
                        is_dirty_final = True

                    cv2.rectangle(frame, (x1, y1), (x2, y2), color, 2)
                    cv2.putText(frame, f"{label}", (x1, y1-10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)

            # Tampilkan di Layar Laptop
            cv2.imshow("TIFA Stream - Expert Logic", frame)

            # Sangat penting agar GUI Windows bisa ter-refresh
            cv2.waitKey(1)

            # Kirim Balik Hasil ke RasPi
            response = {
                "robot_id": robot_id,
                "status": "DIRTY" if is_dirty_final else "CLEAN",
                "process_ms": (time.time() - start_time) * 1000
            }
            await websocket.send(json.dumps(response))

    except websockets.exceptions.ConnectionClosed:
        print(f"[INFO] Koneksi dari Raspberry Pi terputus.")
    except Exception as e:
        print(f"[ERROR] Koneksi bermasalah: {e}")
    finally:
        cv2.destroyAllWindows()

async def main():
    print(f"--- SERVER LOGICAL OVERRIDE AKTIF DI PORT {PORT} ---")
    async with websockets.serve(tifa_override_handler, "0.0.0.0", PORT, ping_interval=None, ping_timeout=None):
        await asyncio.Future()

if __name__ == "__main__":
    asyncio.run(main())