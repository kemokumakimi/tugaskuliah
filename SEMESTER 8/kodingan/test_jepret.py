import cv2

print("Memulai tes OpenNI Kinect...")
cap = cv2.VideoCapture(cv2.CAP_OPENNI2)

if not cap.isOpened():
    print("Gagal membuka OpenNI2. Mencoba OpenNI standar...")
    cap = cv2.VideoCapture(cv2.CAP_OPENNI)

if not cap.isOpened():
    print("Kamera gagal dibuka. Periksa USB dan Udev rules.")
    exit()

print("Kinect berhasil dibuka! Mencoba mengambil frame...")
# Ambil beberapa frame kosong (pemanasan sensor)
for i in range(10):
    cap.grab()

ret, frame = cap.retrieve(cv2.CAP_OPENNI_BGR_IMAGE)

if ret and frame is not None:
    cv2.imwrite("hasil_tes_kinect.jpg", frame)
    print("BERHASIL! Gambar disimpan sebagai 'hasil_tes_kinect.jpg'")
else:
    print("GAGAL mengambil gambar.")

cap.release()
