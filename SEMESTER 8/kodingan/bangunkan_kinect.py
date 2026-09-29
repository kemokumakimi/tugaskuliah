import ctypes
import numpy as np
import cv2
import time

print("Memulai koneksi pancingan ke Kinect...")

try:
    lib = ctypes.CDLL('libfreenect.so')
    lib_sync = ctypes.CDLL('libfreenect_sync.so')

    # 1. Inisialisasi perangkat keras secara mentah
    ctx = ctypes.c_void_p()
    if lib.freenect_init(ctypes.byref(ctx), 0) != 0:
        print("Gagal inisialisasi konteks USB.")
        exit()

    print("Mengubah warna lampu LED Kinect untuk memancing sensor...")
    # 0=Mati, 1=Hijau, 2=Merah, 3=Kuning, 4=Berkedip Hijau
    lib_sync.freenect_sync_set_led(2, 0) # Ubah ke merah
    time.sleep(1)
    lib_sync.freenect_sync_set_led(1, 0) # Kembalikan ke hijau
    time.sleep(1)

    print("Mencoba menarik frame...")
    sync_get_video = lib_sync.freenect_sync_get_video
    sync_get_video.restype = ctypes.c_int
    sync_get_video.argtypes = [ctypes.POINTER(ctypes.c_void_p), ctypes.POINTER(ctypes.c_uint32), ctypes.c_int, ctypes.c_int]

    video_ptr = ctypes.c_void_p()
    timestamp = ctypes.c_uint32()

    # Beri jeda sedikit agar sensor video siap
    time.sleep(2)

    res = sync_get_video(ctypes.byref(video_ptr), ctypes.byref(timestamp), 0, 0)

    if res == 0:
        buffer = ctypes.cast(video_ptr, ctypes.POINTER(ctypes.c_ubyte * (640*480*3))).contents
        frame = np.frombuffer(buffer, dtype=np.uint8).reshape((480, 640, 3))
        frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)
        cv2.imwrite("ctypes_kinect.jpg", frame)
        print("SUKSES! Frame berhasil ditangkap.")
    else:
        print("GAGAL: Timeout atau sensor masih terkunci.")

    lib.freenect_shutdown(ctx)

except Exception as e:
    print(f"Error: {e}")
