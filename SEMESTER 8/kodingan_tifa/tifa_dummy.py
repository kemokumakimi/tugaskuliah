"""
tifa_dummy.py
=============
Simulasi Raspi: mengirim data deteksi meja kotor ke server laptop via WebSocket.
Nanti bisa diganti dengan kode Raspi asli yang mengirim data dari Kinect.

KONFIGURASI:
  - SERVER_IP   : IP laptop yang menjalankan tifa_receiver.py
  - SERVER_PORT : Port server (harus sama dengan tifa_receiver.py)
  - ROBOT_ID    : ID robot/raspi pengirim
  - INTERVAL    : Jeda antar pengiriman (detik)
  - OUTPUT_FILE : Nama file JSON hasil deteksi (di direktori yang sama dengan script ini)
"""

import asyncio
import websockets
import json
import random
import time
import os
import sys

# ===================== KONFIGURASI =====================
SERVER_IP   = "192.168.100.4"   # IP Laptop
SERVER_PORT = 8000             # Port server
ROBOT_ID    = "TIFA-02"          # ID Robot
INTERVAL    = 2.0                 # Detik antar pengiriman
OUTPUT_FILE = "hasil_deteksi.json"  # File output JSON (relatif ke lokasi script)
# =======================================================

# Pastikan OUTPUT_FILE tersimpan di direktori yang sama dengan script ini
SCRIPT_DIR  = os.path.dirname(os.path.abspath(__file__))
OUTPUT_PATH = os.path.join(SCRIPT_DIR, OUTPUT_FILE)


def buat_data_dummy() -> dict:
    """
    Membuat data deteksi meja dummy.
    Nanti bagian ini diganti dengan hasil pembacaan Kinect dari Raspi.
    """
    status = random.choices(["DIRTY", "CLEAN"], weights=[30, 70])[0]  # 30% kotor, 70% bersih

    data = {
        "robot_id"   : ROBOT_ID,
        "timestamp"  : time.strftime("%Y-%m-%dT%H:%M:%S"),
        "status"     : status,
        "confidence" : round(random.uniform(0.75, 0.99), 2),
        "detail"     : {
            "sisa_makanan" : random.choice([True, False]) if status == "DIRTY" else False,
            "tumpahan"     : random.choice([True, False]) if status == "DIRTY" else False,
            "sampah"       : random.choice([True, False]) if status == "DIRTY" else False,
        },
        "source"     : "dummy"   # Ganti jadi "kinect" saat pakai Raspi asli
    }
    return data


def simpan_json_lokal(data: dict):
    """Simpan hasil deteksi ke file JSON di direktori script."""
    # Baca data lama jika file sudah ada
    riwayat = []
    if os.path.exists(OUTPUT_PATH):
        try:
            with open(OUTPUT_PATH, "r") as f:
                riwayat = json.load(f)
            if not isinstance(riwayat, list):
                riwayat = [riwayat]
        except Exception:
            riwayat = []

    riwayat.append(data)

    with open(OUTPUT_PATH, "w") as f:
        json.dump(riwayat, f, indent=2, ensure_ascii=False)


async def kirim_ke_server():
    uri = f"ws://{SERVER_IP}:{SERVER_PORT}"
    print(f"[INFO] Menghubungkan ke {uri}...")

    try:
        async with websockets.connect(uri) as ws:
            print(f"[SUCCESS] Terhubung ke server.")
            print(f"[INFO] Output JSON lokal: {OUTPUT_PATH}\n")

            while True:
                data = buat_data_dummy()

                # Simpan ke file JSON lokal
                simpan_json_lokal(data)

                # Kirim ke server laptop
                await ws.send(json.dumps(data))

                # Tampilkan ringkasan di terminal
                status_label = "[!!!] KOTOR" if data["status"] == "DIRTY" else "[OK]  Bersih"
                print(f"{status_label} | confidence: {data['confidence']} | {data['timestamp']}")

                # Tunggu respons dari server (opsional)
                try:
                    resp = await asyncio.wait_for(ws.recv(), timeout=1.0)
                    resp_data = json.loads(resp)
                    print(f"       Server: {resp_data.get('message', '-')}")
                except asyncio.TimeoutError:
                    pass

                await asyncio.sleep(INTERVAL)

    except Exception as e:
        print(f"\n[CRITICAL] Gagal terhubung: {e}")
        print("Mencoba ulang dalam 5 detik...")
        await asyncio.sleep(5)
        await kirim_ke_server()


if __name__ == "__main__":
    print("=" * 50)
    print("  TIFA DUMMY SENDER")
    print(f"  Server : {SERVER_IP}:{SERVER_PORT}")
    print(f"  Robot  : {ROBOT_ID}")
    print(f"  Output : {OUTPUT_PATH}")
    print("=" * 50)

    # Bersihkan file lama jika ada
    if os.path.exists(OUTPUT_PATH):
        os.remove(OUTPUT_PATH)
        print(f"[INFO] File lama '{OUTPUT_FILE}' dihapus.\n")

    asyncio.run(kirim_ke_server())