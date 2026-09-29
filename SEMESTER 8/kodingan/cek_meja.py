import numpy as np
import cv2
import os

# --- Kamera Intrinsic (Estimasi Kinect v1) ---
CX = 320.0
CY = 240.0
FX = 525.0
FY = 525.0

# Definisi Meja (Contoh: Kiri Atas x1,y1 dan Kanan Bawah x2,y2)
MEJA = {
    "Meja_1": {"x1": 100, "y1": 200, "x2": 250, "y2": 350},
    "Meja_2": {"x1": 350, "y1": 200, "x2": 500, "y2": 350}
}

def get_3d_coordinates(x, y, depth_image):
    """Mengubah koordinat pixel (x,y) menjadi koordinat dunia 3D (X,Y,Z) dalam meter."""
    # Pastikan koordinat dalam batas gambar
    if x < 0 or x >= 640 or y < 0 or y >= 480:
        return None
    
    # Baca nilai depth dalam millimeter dari format FREENECT_DEPTH_REGISTERED
    # index numpy adalah (y, x)
    z_mm = depth_image[y, x]
    
    # 0 biasanya berarti tidak ada data depth (invalid/terlalu dekat/jauh)
    if z_mm == 0:
        return None
        
    z_meters = z_mm / 1000.0
    
    # Pinhole camera model
    x_meters = (x - CX) * z_meters / FX
    y_meters = (y - CY) * z_meters / FY
    
    return (x_meters, y_meters, z_meters)

def cek_meja(x, y):
    """Mengecek pixel (x,y) jatuh di meja berapa."""
    for nama_meja, bbox in MEJA.items():
        if bbox["x1"] <= x <= bbox["x2"] and bbox["y1"] <= y <= bbox["y2"]:
            return nama_meja
    return "Tidak Dikenali"

def jalankan_kamera():
    """Menjalankan program C untuk mengambil frame RGB dan Depth"""
    print("Mengambil gambar dari Kinect...")
    os.system("sudo ./ambil_gambar_kinect")

def load_data():
    """Membaca file test.raw dan depth.raw menjadi numpy array"""
    try:
        # Baca RGB (640x480x3 uint8)
        with open("test.raw", "rb") as f:
            raw_rgb = f.read()
        img_rgb = np.frombuffer(raw_rgb, dtype=np.uint8).reshape((480, 640, 3))
        img_rgb = cv2.cvtColor(img_rgb, cv2.COLOR_RGB2BGR)

        # Baca Depth (640x480 uint16)
        with open("depth.raw", "rb") as f:
            raw_depth = f.read()
        img_depth = np.frombuffer(raw_depth, dtype=np.uint16).reshape((480, 640))
        
        return img_rgb, img_depth
    except Exception as e:
        print(f"Gagal membaca data gambar/depth: {e}")
        return None, None

def proses_kotoran(titik_kotor_pixel):
    """
    titik_kotor_pixel: List dari tuple (x,y) koordinat pixel kotoran yang dideteksi.
    """
    jalankan_kamera()
    img_rgb, img_depth = load_data()
    
    if img_rgb is None or img_depth is None:
        print("Data tidak tersedia.")
        return

    print(f"Memproses {len(titik_kotor_pixel)} titik kotoran...")
    
    for (x, y) in titik_kotor_pixel:
        meja = cek_meja(x, y)
        coords_3d = get_3d_coordinates(x, y, img_depth)
        
        if coords_3d:
            print(f"Kotoran terdeteksi di {meja} pada pixel ({x},{y}).")
            print(f"-> Koordinat 3D (X,Y,Z): ({coords_3d[0]:.3f}m, {coords_3d[1]:.3f}m, {coords_3d[2]:.3f}m)\n")
        else:
            print(f"Kotoran terdeteksi di {meja} pada pixel ({x},{y}).")
            print(f"-> Gagal mendapatkan koordinat 3D (depth tidak terbaca / di luar jangkauan).\n")

if __name__ == "__main__":
    # Contoh Integrasi: Misalkan algoritma visi Anda (YOLO, OpenCV) mendeteksi kotoran
    # di pixel-pixel berikut:
    titik_kotor_simulasi = [
        (150, 250), # Jatuh di Meja 1
        (400, 300), # Jatuh di Meja 2
        (50, 50)    # Jatuh di tempat yang tidak dikenali
    ]
    
    proses_kotoran(titik_kotor_simulasi)
