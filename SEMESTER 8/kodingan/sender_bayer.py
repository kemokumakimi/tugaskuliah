import cv2
import socket
import struct
import numpy as np

# --- CONFIG ---
LAPTOP_IP = '192.168.100.118' # Pastikan IP Laptop Benar!
PORT = 8000

print("Menginisialisasi Kamera /dev/video0 (Format GRBG)...")

cap = cv2.VideoCapture(0, cv2.CAP_V4L2)

# PAKSA KAMERA MENGGUNAKAN FORMAT RAW (Bayer)
cap.set(cv2.CAP_PROP_CONVERT_RGB, 0) # Matikan auto-convert
cap.set(cv2.CAP_PROP_FORMAT, -1)     # Ambil data mentah

if not cap.isOpened():
    print("[ERROR] Kamera tidak bisa dibuka!")
    exit()

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    print(f"Menghubungkan ke Laptop di {LAPTOP_IP}:{PORT}...")
    client_socket.connect((LAPTOP_IP, PORT))
    print("[SUCCESS] Terhubung! Memulai pengiriman gambar...")

    while True:
        ret, frame_raw = cap.read()
        if not ret or frame_raw is None:
            print("Gagal ambil frame...", end="\r")
            continue

        # Coba Konversi dari format Bayer (GRBG) ke BGR (Warna biasa OpenCV)
        try:
            # Karena cap.read() pada format mentah seringkali mengembalikan array 1D atau bentuk aneh
            # Kita pastikan bentuknya benar
            if len(frame_raw.shape) == 2 or frame_raw.shape[2] == 1:
                frame_bgr = cv2.cvtColor(frame_raw, cv2.COLOR_BayerGB2BGR)
            else:
                 # Jika ternyata sudah 3 channel, biarkan saja
                 frame_bgr = frame_raw
        except Exception as e:
            # Jika konversi gagal, kirim saja gambar mentahnya (mungkin hitam putih/berantakan)
            # asalkan jalan dulu
            frame_bgr = frame_raw

        # Resize jadi kecil agar transmisi cepat
        frame_bgr = cv2.resize(frame_bgr, (320, 240))

        # Encode ke JPEG
        _, frame_encoded = cv2.imencode('.jpg', frame_bgr, [int(cv2.IMWRITE_JPEG_QUALITY), 50])
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
