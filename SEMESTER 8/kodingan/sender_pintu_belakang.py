import cv2
import socket
import struct
import numpy as np

LAPTOP_IP = '192.168.100.118'
PORT = 8000

print("Membaca stream dari /dev/video0 secara pasif...")

# Buka video TANPA properti apapun (pasif)
cap = cv2.VideoCapture('/dev/video0', cv2.CAP_V4L2)

if not cap.isOpened():
    print("[ERROR] /dev/video0 tidak ada! Pastikan freenect-camtest sedang jalan atau modprobe gspca_kinect sudah aktif.")
    exit()

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    print(f"Menghubungkan ke {LAPTOP_IP}:{PORT}...")
    client_socket.connect((LAPTOP_IP, PORT))
    print("[SUCCESS] Terhubung ke Laptop!")

    while True:
        # Cukup baca saja, jangan set properti
        ret, frame = cap.read()

        if not ret or frame is None:
            # Jika gagal, coba terus
            continue

        # Konversi warna jika aneh (opsional, tapi biasanya gspca_kinect otomatis jadi BGR)

        frame = cv2.resize(frame, (320, 240))
        _, frame_encoded = cv2.imencode('.jpg', frame, [int(cv2.IMWRITE_JPEG_QUALITY), 40])
        data_bytes = np.array(frame_encoded).tobytes()

        client_socket.sendall(struct.pack("Q", len(data_bytes)) + data_bytes)
        print(f"Streaming... Ukuran: {len(data_bytes)} bytes", end="\r")

except Exception as e:
    print(f"\n[ERROR] {e}")
finally:
    cap.release()
    client_socket.close()
