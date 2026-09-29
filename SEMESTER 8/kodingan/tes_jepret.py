import ctypes
import numpy as np
import cv2

print("Memulai koneksi langsung ke libfreenect C++ API...")

try:
    # Memuat library C++ yang tadi kita kompilasi
    freenect = ctypes.CDLL('libfreenect_sync.so')

    # Menyiapkan fungsi penangkap video dari C++
    # void freenect_sync_get_video(void **video, uint32_t *timestamp, int index, int fmt)
    sync_get_video = freenect.freenect_sync_get_video
    sync_get_video.restype = ctypes.c_int
    sync_get_video.argtypes = [ctypes.POINTER(ctypes.c_void_p), ctypes.POINTER(ctypes.c_uint32), ctypes.c_int, ctypes.c_int]

    # Menyiapkan pointer untuk menampung gambar
    video_ptr = ctypes.c_void_p()
    timestamp = ctypes.c_uint32()

    # Format 0 adalah RGB
    FREENECT_VIDEO_RGB = 0

    print("Berhasil memuat library. Sedang menarik frame...")

    # Panggil fungsi C++
    res = sync_get_video(ctypes.byref(video_ptr), ctypes.byref(timestamp), 0, FREENECT_VIDEO_RGB)

    if res != 0:
        print("ERROR: freenect_sync_get_video mengembalikan kode kegagalan.")
        exit()

    # Ukuran gambar Kinect v1 RGB adalah 640 x 480 dengan 3 channel warna (R, G, B)
    width = 640
    height = 480
    buffer_size = width * height * 3

    # Mengubah raw memory C++ ke dalam bentuk array Python (Numpy)
    buffer = ctypes.cast(video_ptr, ctypes.POINTER(ctypes.c_ubyte * buffer_size)).contents
    frame_rgb = np.frombuffer(buffer, dtype=np.uint8).reshape((height, width, 3))

    # Karena OpenCV menggunakan format BGR, kita balik urutan warnanya
    frame_bgr = cv2.cvtColor(frame_rgb, cv2.COLOR_RGB2BGR)

    cv2.imwrite("ctypes_kinect.jpg", frame_bgr)
    print("SUKSES LUAR BIASA! Gambar disimpan sebagai 'ctypes_kinect.jpg'")

except OSError:
    print("CRITICAL ERROR: 'libfreenect_sync.so' tidak ditemukan di sistem.")
    print("Pastikan Anda sudah menjalankan 'sudo ldconfig' setelah 'make install'.")
except Exception as e:
    print(f"ERROR: {e}")
