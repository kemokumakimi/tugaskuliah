import cv2
import roslibpy
import base64
import time
import subprocess
import os
import threading

# --- CONFIG ---
IP_LAPTOP = '192.168.100.118'

print(f"Mencoba terhubung ke ROSBridge di {IP_LAPTOP}:9090...")
try:
    client = roslibpy.Ros(host=IP_LAPTOP, port=9090)
    client.run()
    print("Terhubung ke ROSBridge!")
except Exception as e:
    print(f"Gagal terhubung ke ROSBridge: {e}")
    exit()

topic = roslibpy.Topic(client, '/camera/image/compressed', 'sensor_msgs/CompressedImage')

print("Menginisialisasi Kamera Kinect menggunakan OpenCV...")

# Kita coba cara lain dari OpenCV: CAP_ANY (Biarkan OpenCV mencari driver terbaik)
cap = cv2.VideoCapture(0, cv2.CAP_ANY)

# JANGAN set prop format atau apapun. Biarkan default.
time.sleep(2)

if not cap.isOpened():
    print("[ERROR] Kamera tidak bisa dibuka!")
    client.terminate()
    exit()

try:
    while client.is_connected:
        # Panggil read tapi tanpa batas timeout yang kaku
        ret, frame = cap.read()

        if not ret or frame is None:
            print("Gagal, mencoba lagi...", end="\r")

            # Trik reset kamera on-the-fly jika hang
            cap.release()
            time.sleep(1)
            cap = cv2.VideoCapture(0, cv2.CAP_ANY)
            continue

        # OPTIMASI: Kecilkan resolusi
        frame = cv2.resize(frame, (640, 480))
        _, buffer = cv2.imencode('.jpg', frame, [cv2.IMWRITE_JPEG_QUALITY, 50])

        jpg_as_text = base64.b64encode(buffer).decode('utf-8')

        topic.publish(roslibpy.Message({
            'format': 'jpeg',
            'data': jpg_as_text
        }))

        print("Streaming frame ke ROS 2...", end="\r")
        time.sleep(0.05) 

except KeyboardInterrupt:
    print("\nStreaming dihentikan")
finally:
    if cap.isOpened():
        cap.release()
    client.terminate()
