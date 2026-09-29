import cv2
import socket
import struct
import numpy as np
import time
import urllib.request

# --- CONFIG ---
LAPTOP_IP = '192.168.100.118'
PORT = 8000
MJPG_URL = 'http://127.0.0.1:8080/?action=snapshot'

def connect_to_laptop():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        print(f"Menghubungkan ke Laptop di {LAPTOP_IP}:{PORT}...")
        client_socket.connect((LAPTOP_IP, PORT))
        print("[SUCCESS] Terhubung ke Laptop!")
        return client_socket
    except Exception as e:
        print(f"[ERROR] Gagal terhubung ke Laptop: {e}")
        return None

print("--- TIFA ROBOT: ROS 2 TCP SENDER (VIA MJPG) ---")

while True:
    client_socket = connect_to_laptop()
    if not client_socket:
        time.sleep(5)
        continue

    try:
        while True:
            # Ambil satu frame gambar langsung dari mjpg-streamer di background
            try:
                req = urllib.request.urlopen(MJPG_URL, timeout=2)
                arr = np.asarray(bytearray(req.read()), dtype=np.uint8)
                frame = cv2.imdecode(arr, -1)
            except Exception as req_err:
                print(f"[WARN] Menunggu mjpg-streamer... {req_err}", end="\r")
                time.sleep(1)
                continue

            if frame is None:
                continue

            # Resize & Encode
            resized = cv2.resize(frame, (320, 240))
            _, buffer = cv2.imencode('.jpg', resized, [cv2.IMWRITE_JPEG_QUALITY, 50])
            data_bytes = np.array(buffer).tobytes()

            # Kirim ukuran data + data gambarnya (Format TCP untuk kinect_bridge ROS 2)
            client_socket.sendall(struct.pack("Q", len(data_bytes)) + data_bytes)
            print(f"Streaming Kinect... Ukuran: {len(data_bytes)} bytes ", end="\r")

            time.sleep(0.05)

    except Exception as e:
        print(f"\n[ERR] Koneksi terputus: {e}")
    finally:
        if client_socket:
            client_socket.close()

    print("Menyambung ulang ke laptop dalam 5 detik...")
    time.sleep(5)
