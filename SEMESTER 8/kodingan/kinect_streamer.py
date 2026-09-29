import cv2
import roslibpy
import base64
import time

# IP Laptop Anda
IP_LAPTOP = '192.168.100.118'

print(f"Mencoba terhubung ke ROSBridge di {IP_LAPTOP}:9090...")
try:
    client = roslibpy.Ros(host=IP_LAPTOP, port=9090)
    client.run()
    print("Terhubung ke ROSBridge!")
except Exception as e:
    print(f"Gagal terhubung ke ROSBridge: {e}")
    print("Pastikan 'ros2 run rosbridge_server rosbridge_websocket' sudah jalan di Laptop.")
    exit()

topic = roslibpy.Topic(client, '/camera/image/compressed', 'sensor_msgs/CompressedImage')

print("Membuka kamera Kinect (/dev/video0)...")
# Gunakan V4L2 agar lebih stabil di Linux
cap = cv2.VideoCapture(0, cv2.CAP_V4L2)

# Beri waktu kamera untuk pemanasan
time.sleep(2)

if not cap.isOpened():
    print("[ERROR] Kamera tidak bisa dibuka! Cek kabel USB atau jalankan 'sudo modprobe uvcvideo'.")
    client.terminate()
    exit()

print(f"Kamera berhasil dibuka! Streaming Kinect to {IP_LAPTOP}...")

try:
    while client.is_connected:
        ret, frame = cap.read()
        if not ret:
            print("Gagal membaca frame kamera, mencoba lagi...", end="\r")
            time.sleep(0.5)
            continue

        # OPTIMASI: Kecilkan resolusi agar lancar di WiFi
        frame = cv2.resize(frame, (640, 480))
        _, buffer = cv2.imencode('.jpg', frame, [cv2.IMWRITE_JPEG_QUALITY, 50])

        jpg_as_text = base64.b64encode(buffer).decode('utf-8')

        topic.publish(roslibpy.Message({
            'format': 'jpeg',
            'data': jpg_as_text
        }))

        print("Streaming frame...", end="\r")
        time.sleep(0.05) 

except KeyboardInterrupt:
    print("\nStreaming dihentikan oleh pengguna.")
finally:
    if cap.isOpened():
        cap.release()
    client.terminate()
