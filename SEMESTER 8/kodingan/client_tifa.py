import cv2
import asyncio
import websockets
import base64
import json
import time

# --- KONFIGURASI ---
# SALIN URL DARI GOOGLE COLAB (Contoh: wss://abcd-efgh.trycloudflare.com)
CLOUD_URL = "wss://dude-generous-united-apparently.trycloudflare.com"
VIDEO_PATH = "video_tes.mp4"
TARGET_WIDTH = 480

async def stream_to_cloud():
    print(f"Menghubungkan ke Cloud Brain di {CLOUD_URL}...")
    try:
        # Gunakan ssl=True jika menggunakan wss://
        async with websockets.connect(CLOUD_URL) as websocket:
            print("[SUCCESS] Terhubung ke Cloud Brain Google!")
            cap = cv2.VideoCapture(VIDEO_PATH)

            while cap.isOpened():
                ret, frame = cap.read()
                if not ret:
                    cap.set(cv2.CAP_PROP_POS_FRAMES, 0)
                    continue

                resized = cv2.resize(frame, (TARGET_WIDTH, int(frame.shape[0] * (TARGET_WIDTH / frame.shape[1]))))
                _, buffer = cv2.imencode('.jpg', resized, [cv2.IMWRITE_JPEG_QUALITY, 60])
                img_b64 = base64.b64encode(buffer).decode('utf-8')

                await websocket.send(json.dumps({"image": img_b64}))

                response = await websocket.recv()
                result = json.loads(response)

                if result.get("goal"):
                    print(f"\n[!!!] GOAL: MEJA KOTOR TERDETEKSI!")
                else:
                    print(f"[.] Scanning... Latency: {result.get('process_ms', 0):.1f}ms", end="\r")

                await asyncio.sleep(0.05)
            cap.release()
    except Exception as e:
        print(f"\n[ERROR] {e}")
        print("Mencoba menyambung kembali dalam 5 detik...")
        await asyncio.sleep(5)
        await stream_to_cloud()

if __name__ == "__main__":
    asyncio.run(stream_to_cloud())
