import cv2
import socket
import struct
import numpy as np

import sys
# PENTING: Tambahkan ini agar Python bisa menemukan freenect manual!
sys.path.append('/home/tifa2/libfreenect/wrappers/python')
try:
    import freenect
except ImportError:
    print("[ERROR] Library freenect tidak ditemukan di /home/tifa2/libfreenect/wrappers/python")
    exit()

# CONFIG LAPTOP
LAPTOP_IP = '192.168.100.118' 
PORT = 8000

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print(f"Menghubungkan ke Laptop {LAPTOP_IP}:{PORT}...")

try:
    client_socket.connect((LAPTOP_IP, PORT))
    print("[SUCCESS] Terhubung ke Laptop!")

    while True:
        # Panggil Kinect langsung lewat driver Freenect
        data, _ = freenect.sync_get_video()
        if data is None:
            continue

        frame = cv2.cvtColor(data, cv2.COLOR_RGB2BGR)

        # Resize dan Encode
        frame = cv2.resize(frame, (320, 240))
        _, frame_encoded = cv2.imencode('.jpg', frame, [int(cv2.IMWRITE_JPEG_QUALITY), 40])
        data_bytes = np.array(frame_encoded).tobytes()

        # Kirim data
        client_socket.sendall(struct.pack("Q", len(data_bytes)) + data_bytes)
        print(f"Streaming Kinect... Ukuran: {len(data_bytes)} bytes", end="\r")

except Exception as e:
    print(f"\n[ERROR] {e}")
finally:
    client_socket.close()
