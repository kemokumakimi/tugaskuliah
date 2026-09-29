import cv2
import socket
import struct
import numpy as np

# --- CONFIG ---
LAPTOP_IP = '192.168.100.118' # Ganti jika IP Laptop berubah
PORT = 8000

print("Menginisialisasi Kamera /dev/video0...")

# Cara paling standar memanggil webcam di OpenCV Linux
cap = cv2.VideoCapture(0)

# Coba paksa ke MJPG jika V4L2 timeout
cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))

if not cap.isOpened():
    print("[ERROR] Kamera tidak bisa dibuka!")
    exit()

# Coba baca 1 frame kosong untuk memancing kamera (Warm-up)
for _ in range(5):
    cap.read()

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    print(f"Menghubungkan ke Laptop di {LAPTOP_IP}:{PORT}...")
    client_socket.connect((LAPTOP_IP, PORT))
    print("[SUCCESS] Terhubung! Memulai pengiriman gambar...")

    while True:
        ret, frame = cap.read()
        if not ret or frame is None:
            print("Timeout/Gagal ambil frame... mencoba lagi.")
            continue

        # Resize jadi kecil
        frame = cv2.resize(frame, (320, 240))

        # Encode ke JPEG
        _, frame_encoded = cv2.imencode('.jpg', frame, [int(cv2.IMWRITE_JPEG_QUALITY), 40])
        data_bytes = np.array(frame_encoded).tobytes()

        # Kirim ukuran data + data gambarnya
        client_socket.sendall(struct.pack("Q", len(data_bytes)) + data_bytes)
        print(f"Streaming Kinect... Ukuran: {len(data_bytes)} bytes", end="\r")

except ConnectionRefusedError:
    print("\n[ERROR] Koneksi ditolak! Pastikan kinect_bridge di Laptop sudah jalan.")
except Exception as e:
    print(f"\n[ERROR] {e}")
finally:
    cap.release()
    client_socket.close()
