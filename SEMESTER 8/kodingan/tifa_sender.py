import cv2
import roslibpy
import base64
import time
import os
import numpy as np

IP_LAPTOP = '192.168.100.118'

print(f"Mencoba terhubung ke ROSBridge di {IP_LAPTOP}...")
try:
    client = roslibpy.Ros(host=IP_LAPTOP, port=9090)
    client.run()
    print("Terhubung ke ROSBridge!")
except Exception as e:
    print(f"Gagal terhubung ke ROSBridge: {e}")
    exit()

topic = roslibpy.Topic(client, '/camera/image/compressed', 'sensor_msgs/CompressedImage')

print("Mulai mengambil gambar via C++...")

while client.is_connected:
    # 1. Panggil program C
    os.system("sudo ./ambil_gambar_kinect")

    # 2. Baca file hasil jepretan
    try:
        with open("test.raw", "rb") as f:
            raw_data = f.read()

        if len(raw_data) != 640*480*3:
            continue

        # 3. Konversi
        image = np.frombuffer(raw_data, dtype=np.uint8).reshape((480, 640, 3))
        image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

        # 4. Resize & Encode
        image = cv2.resize(image, (320, 240))
        _, buffer = cv2.imencode('.jpg', image, [cv2.IMWRITE_JPEG_QUALITY, 50])
        jpg_as_text = base64.b64encode(buffer).decode('utf-8')

        # 5. Kirim
        topic.publish(roslibpy.Message({
            'format': 'jpeg',
            'data': jpg_as_text
        }))
        print("Berhasil mengirim 1 frame ke ROS 2!", end="\r")

    except Exception as e:
        pass

    time.sleep(0.1)
