import cv2
import socket
import struct
import numpy as np
import time
import os

# --- CONFIG ---
LAPTOP_IP = '192.168.100.118'  # Pastikan ini IP Laptop yang benar
PORT = 8000
TARGET_WIDTH = 640

def hard_reset_kinect():
    print("\n[RECOVERY] Menjalankan Hard Reset Modul Kinect (uvcvideo)...")
    # Menggunakan sudo -S dengan password "tifa2"
    os.system('echo tifa2 | sudo -S modprobe -r uvcvideo')
    time.sleep(2)
    os.system('echo tifa2 | sudo -S modprobe uvcvideo')
    time.sleep(3)
    print("[RECOVERY] Modul uvcvideo berhasil di-reload.")

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

print("--- TIFA ROBOT: ROS 2 TCP SENDER ---")

consecutive_failures = 0

while True:
    client_socket = connect_to_laptop()
    if not client_socket:
        print("Menyambung ulang dalam 5 detik...")
        time.sleep(5)
        continue

    cap = None
    try:
        # Inisialisasi Kinect (V4L2 + YUYV) persis seperti script asli
        print("[INFO] Menginisialisasi Kamera...")
        cap = cv2.VideoCapture(0, cv2.CAP_V4L2)
        cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'YUYV'))
        time.sleep(2.0) # WARMUP
        cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

        if not cap.isOpened():
            print("[ERROR] Kinect tidak merespons. Melakukan Hard Reset...")
            consecutive_failures += 1
            if consecutive_failures >= 1:
                hard_reset_kinect()
                consecutive_failures = 0
            time.sleep(5)
            continue

        print("[INFO] Sinkronisasi data Kinect (Warm up)...")
        for _ in range(15): cap.grab()
        consecutive_failures = 0
        print("[SUCCESS] Kamera siap! Memulai streaming...")

        while True:
            ret, frame = cap.read()
            if not ret:
                print("\n[WARN] Kinect Stream Putus (Timeout)! Keluar loop untuk reset...")
                break

            # Resize & Encode
            resized = cv2.resize(frame, (320, 240)) # Ukuran kecil agar ROS2 ringan
            _, buffer = cv2.imencode('.jpg', resized, [cv2.IMWRITE_JPEG_QUALITY, 50])
            data_bytes = np.array(buffer).tobytes()

            # Kirim ukuran data + data gambarnya (Format TCP untuk kinect_bridge ROS 2)
            client_socket.sendall(struct.pack("Q", len(data_bytes)) + data_bytes)
            print(f"Streaming Kinect... Ukuran: {len(data_bytes)} bytes ", end="\r")

            time.sleep(0.05) # Beri jeda sedikit agar jaringan tidak banjir

    except Exception as e:
        print(f"\n[ERR] Masalah Sistem: {e}")
    finally:
        if cap:
            cap.release()
            print("\n[INFO] Kamera Dilepas.")
        if client_socket:
            client_socket.close()
            print("[INFO] Socket ditutup.")

    print("Menyambung ulang kamera dan laptop dalam 5 detik...")
    hard_reset_kinect()
    time.sleep(5)
