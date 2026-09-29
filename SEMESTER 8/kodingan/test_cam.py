
import cv2
import time

print('Membuka kamera...')
cap = cv2.VideoCapture(0, cv2.CAP_V4L2)
if not cap.isOpened():
    print('GAGAL: Kamera tidak terbuka.')
    exit(1)

print('Kamera terbuka. Menunggu frame...')
time.sleep(2)

ret, frame = cap.read()
if ret:
    print(f'BERHASIL: Frame diterima dengan resolusi {frame.shape}')
else:
    print('GAGAL: Timeout saat membaca frame.')

cap.release()
