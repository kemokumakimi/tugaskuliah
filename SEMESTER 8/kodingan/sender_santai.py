import cv2
import roslibpy
import base64
import time

IP_LAPTOP = '192.168.100.118'

print(f"Menghubungkan ke ROSBridge di {IP_LAPTOP}...")
try:
    client = roslibpy.Ros(host=IP_LAPTOP, port=9090)
    client.run()
    print("Terhubung ke ROSBridge!")
except Exception as e:
    print(f"Gagal: {e}")
    exit()

topic = roslibpy.Topic(client, '/camera/image/compressed', 'sensor_msgs/CompressedImage')

print("Membuka kamera /dev/video0...")

# Buka kamera
cap = cv2.VideoCapture(0, cv2.CAP_V4L2)

# PAKSA KAMERA MENGIRIM FORMAT MENTAH (Mencegah Timeout)
cap.set(cv2.CAP_PROP_CONVERT_RGB, 0)
cap.set(cv2.CAP_PROP_FORMAT, -1)

# Beri waktu kamera pemanasan
time.sleep(1)

if not cap.isOpened():
    print("[ERROR] Kamera tidak bisa dibuka!")
    client.terminate()
    exit()

try:
    while client.is_connected:
        ret, frame_raw = cap.read()
        if not ret or frame_raw is None:
            continue

        # Konversi warna cepat di RAM (Tidak menyentuh Harddisk)
        try:
            if len(frame_raw.shape) == 2:
                frame = cv2.cvtColor(frame_raw, cv2.COLOR_BayerGB2BGR)
            else:
                frame = frame_raw
        except:
            frame = frame_raw

        # Pastikan ukuran 640x480
        frame = cv2.resize(frame, (640, 480))

        # Encode langsung ke JPEG (Kualitas 60 cukup bagus dan ringan)
        _, buffer = cv2.imencode('.jpg', frame, [int(cv2.IMWRITE_JPEG_QUALITY), 60])
        jpg_as_text = base64.b64encode(buffer).decode('utf-8')

        topic.publish(roslibpy.Message({
            'format': 'jpeg',
            'data': jpg_as_text
        }))

        # Sedikit jeda agar WiFi tidak 'sesak napas'
        time.sleep(0.05) 

except KeyboardInterrupt:
    print("\nStreaming dihentikan")
finally:
    cap.release()
    client.terminate()
