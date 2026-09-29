import cv2
import asyncio
import websockets
import base64
import json
import time
import socket
import os

# --- KONFIGURASI JARINGAN ---
SERVER_IP = "192.168.137.1"
SERVER_PORT = 8000
ROBOT_ID = "TIFA-02"
TARGET_WIDTH = 640

# --- KONFIGURASI ROS BRIDGE (UDP) ---
# Mengirim sinyal ke localhost port 5005 untuk tim Navigasi ROS
ROS_BRIDGE_IP = "127.0.0.1"
ROS_BRIDGE_PORT = 5005
udp_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def send_to_ros(payload):
    """Kirim hasil deteksi ke sistem ROS Navigasi via UDP"""
    try:
        json_data = json.dumps(payload)
        udp_sock.sendto(json_data.encode(), (ROS_BRIDGE_IP, ROS_BRIDGE_PORT))
    except Exception as e:
        print(f"\n[ROS_ERR] Gagal kirim ke ROS: {e}")

def hard_reset_kinect():
    print("\n[RECOVERY] Menjalankan Hard Reset Modul Kinect (uvcvideo)...")
    # Menggunakan sudo -S dengan password "tifa2"
    os.system('echo tifa2 | sudo -S modprobe -r uvcvideo')
    time.sleep(2)
    os.system('echo tifa2 | sudo -S modprobe uvcvideo')
    time.sleep(3)
    print("[RECOVERY] Modul uvcvideo berhasil di-reload.")

async def stream_to_server():
    consecutive_failures = 0

    while True: # Loop Utama: Mencoba menyambung kembali jika koneksi server/kamera putus
        uri = f"ws://{SERVER_IP}:{SERVER_PORT}"
        print(f"\n[INFO] Mencoba menyambung ke Brain Server di {uri}...")

        cap = None
        try:
            async with websockets.connect(uri) as websocket:
                print("[SUCCESS] Terhubung ke Brain Server.")

                # Inisialisasi Kinect (V4L2 + MJPG)
                cap = cv2.VideoCapture(0, cv2.CAP_V4L2)
                cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'YUYV'))
                await asyncio.sleep(2.0) # WARMUP
                cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
                cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

                if not cap.isOpened():
                    print("[ERROR] Kinect tidak merespons. Cek kabel atau service lain.")
                    consecutive_failures += 1
                    if consecutive_failures >= 3:
                        hard_reset_kinect()
                        consecutive_failures = 0
                    await asyncio.sleep(5)
                    continue

                print("[INFO] Sinkronisasi data Kinect...")
                for _ in range(15): cap.grab()

                # Jika berhasil sinkronisasi, reset counter kegagalan
                consecutive_failures = 0

                while True: # Loop Frame: Mengirim gambar secara real-time
                    ret, frame = cap.read()
                    if not ret:
                        print("\n[WARN] Kinect Stream Putus (Timeout)! Mencoba Reset...")
                        # Jika stream putus di tengah jalan, kita anggap butuh hard reset langsung
                        break

                    # Resize & Encode sesuai spesifikasi hardware TIFA
                    resized = cv2.resize(frame, (TARGET_WIDTH, 480))
                    _, buffer = cv2.imencode('.jpg', resized, [cv2.IMWRITE_JPEG_QUALITY, 65])
                    img_b64 = base64.b64encode(buffer).decode('utf-8')

                    # 1. Kirim Gambar ke Server PC (Windows)
                    await websocket.send(json.dumps({"robot_id": ROBOT_ID, "image": img_b64}))

                    # 2. Terima Hasil Deteksi
                    response = await asyncio.wait_for(websocket.recv(), timeout=10.0)
                    result = json.loads(response)

                    # 3. KIRIM KE NAVIGASI ROS (Format JSON Standar)
                    ros_payload = {
                        "source": "kinect_vision",
                        "timestamp": time.time(),
                        "table_status": result.get("condition"),
                        "goal_signal": result.get("goal"),
                        "raw_predictions": result.get("details", []) # Koordinat objek presisi
                    }
                    send_to_ros(ros_payload)

                    # 4. Tampilan Status di Terminal RasPi
                    if result.get("goal"):
                        print(f"[!!!] STATUS: {result['condition']} (DIRTY DETECTED)      ", end="\r")
                    else:
                        print(f"[.] Scanning... ({result['condition']})                     ", end="\r")

                    await asyncio.sleep(0.1)

        except Exception as e:
            print(f"\n[ERR] Masalah Sistem: {e}")
        finally:
            if cap:
                cap.release()
                print("\n[INFO] Kamera Dilepas.")

        print("Menyambung ulang dalam 5 detik...")
        
        # Panggil hard reset jika loop terputus karena stream mati
        hard_reset_kinect()
        
        await asyncio.sleep(5)

if __name__ == "__main__":
    print("--- TIFA ROBOT: AUTO-DETECTION SYSTEM (ROS-READY) ---")
    asyncio.run(stream_to_server())
