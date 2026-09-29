import cv2
import roslibpy
import base64
import time
import numpy as np

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

print("Membuka kamera Kinect (Mode Raw/Bayer)...")
cap = cv2.VideoCapture(0, cv2.CAP_V4L2)

# Paksa ambil data mentah agar tidak timeout
cap.set(cv2.CAP_PROP_CONVERT_RGB, 0)
cap.set(cv2.CAP_PROP_FORMAT, -1)

time.sleep(2) # Warmup

if not cap.isOpened():
    print("[ERROR] Kamera tidak bisa dibuka!")
    client.terminate()
    exit()

try:
    while client.is_connected:
        ret, frame_raw = cap.read()

        if not ret or frame_raw is None:
            print("Timeout/Gagal, coba lagi...", end="\r")
            time.sleep(0.5)
            continue

        # Penanganan Otomatis Format Gambar
        if len(frame_raw.shape) == 2:
            # Format Bayer 1 Channel
            try:
                frame = cv2.cvtColor(frame_raw, cv2.COLOR_BayerGB2BGR)
            except:
                frame = cv2.cvtColor(frame_raw, cv2.COLOR_GRAY2BGR)
        elif len(frame_raw.shape) == 3 and frame_raw.shape[2] == 2:
            # Format YUYV 2 Channel
            frame = cv2.cvtColor(frame_raw, cv2.COLOR_YUV2BGR_YUYV)
        else:
            # Format standar
            frame = frame_raw

        # Resize dan Encode ke JPEG
        frame = cv2.resize(frame, (640, 480))
        _, buffer = cv2.imencode('.jpg', frame, [int(cv2.IMWRITE_JPEG_QUALITY), 50])

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
