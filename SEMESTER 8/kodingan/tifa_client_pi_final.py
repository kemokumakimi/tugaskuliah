import cv2
import asyncio
import websockets
import base64
import json
import time
import os
import subprocess
import numpy as np

# --- KONFIGURASI ---
SERVER_IP = "192.168.100.4"  # IP Laptop Anda
SERVER_PORT = 8000
ROBOT_ID = "TIFA-02"

def grab_snapshot_linux():
    """Memanggil program C untuk mengambil gambar secara paksa dan aman dari Kinect"""
    try:
        # Panggil program C kita yang sangat ringan
        subprocess.run(["sudo", "./ambil_gambar_kinect"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, timeout=4.0)

        # Baca file raw (mentah) RGB yang dihasilkan program C
        if os.path.exists("snap_kinect.raw"):
            with open("snap_kinect.raw", "rb") as f:
                raw_data = f.read()

            if len(raw_data) == 640 * 480 * 3:
                frame_rgb = np.frombuffer(raw_data, dtype=np.uint8).reshape((480, 640, 3))
                # OpenCV menggunakan format BGR, jadi kita ubah dari RGB
                frame_bgr = cv2.cvtColor(frame_rgb, cv2.COLOR_RGB2BGR)
                return frame_bgr
    except Exception as e:
        # Abaikan error, kembalikan None agar sistem mencoba lagi
        pass
    return None

async def stream_to_cloud():
    uri = f"ws://{SERVER_IP}:{SERVER_PORT}"
    print(f"[INFO] Menghubungkan ke {uri}...")

    try:
        async with websockets.connect(uri) as websocket:
            print("[SUCCESS] Terhubung ke Cloud Brain.")

            while True:
                # 1. Ambil 1 foto via program C (Anti-Hang)
                frame = grab_snapshot_linux()

                if frame is None:
                    print("[WARNING] Kinect tidak merespon, mencoba lagi...", end="\r")
                    await asyncio.sleep(0.5) # Tunggu sebentar agar USB bernapas
                    continue

                # Bersihkan tulisan warning jika berhasil
                print("                                              ", end="\r")

                # 2. Pengecilan Gambar (Opsional, di sini kita biarkan 640x480)
                # Diubah ke format JPG dengan kualitas 70% agar pengiriman cepat
                _, buffer = cv2.imencode('.jpg', frame, [cv2.IMWRITE_JPEG_QUALITY, 70])
                img_b64 = base64.b64encode(buffer).decode('utf-8')

                # 3. Kirim Gambar via Jaringan ke Laptop
                payload = {"robot_id": ROBOT_ID, "image": img_b64}
                await websocket.send(json.dumps(payload))

                # 4. Terima Deteksi dari Model AI di Laptop
                try:
                    response = await asyncio.wait_for(websocket.recv(), timeout=1.0)
                    result = json.loads(response)
                    if result.get("status") == "DIRTY":
                        print(f"\a[!!!] MEJA KOTOR DETECTED!                  ")
                    else:
                        print(f"[.] Meja Bersih...                          ", end="\r")
                except asyncio.TimeoutError:
                    pass

    except Exception as e:
        print(f"\n[CRITICAL] Error Jaringan: {e}")
        print("Mencoba menyambung kembali dalam 5 detik...")
        await asyncio.sleep(5)
        await stream_to_cloud()

if __name__ == "__main__":
    # Bersihkan file sisa jika ada saat program baru dimulai
    if os.path.exists("snap_kinect.raw"):
        os.remove("snap_kinect.raw")

    asyncio.run(stream_to_cloud())
