"""
tifa_receiver.py
================
Server WebSocket di Laptop: menerima data deteksi meja kotor dari Raspi (atau dummy),
lalu menyimpan hasilnya ke file JSON di direktori yang sama dengan script ini.

KONFIGURASI:
  - HOST        : IP yang di-listen (0.0.0.0 = terima dari semua interface)
  - PORT        : Port server (harus sama dengan yang dipakai client/Raspi)
  - OUTPUT_FILE : Nama file JSON hasil deteksi (di direktori yang sama dengan script ini)
"""

import asyncio
import websockets
import json
import os
import time

# ===================== KONFIGURASI =====================
HOST        = "0.0.0.0"          # Dengarkan dari semua interface
PORT        = 8000                # Port server
OUTPUT_FILE = "hasil_deteksi.json"  # File output JSON
# =======================================================

# Pastikan OUTPUT_FILE tersimpan di direktori yang sama dengan script ini
SCRIPT_DIR  = os.path.dirname(os.path.abspath(__file__))
OUTPUT_PATH = os.path.join(SCRIPT_DIR, OUTPUT_FILE)


def simpan_json(data: dict):
    """Simpan data deteksi ke file JSON (append ke list)."""
    riwayat = []
    if os.path.exists(OUTPUT_PATH):
        try:
            with open(OUTPUT_PATH, "r") as f:
                riwayat = json.load(f)
            if not isinstance(riwayat, list):
                riwayat = [riwayat]
        except Exception:
            riwayat = []

    # Tambah timestamp penerimaan dari sisi server
    data["received_at"] = time.strftime("%Y-%m-%dT%H:%M:%S")
    riwayat.append(data)

    with open(OUTPUT_PATH, "w") as f:
        json.dump(riwayat, f, indent=2, ensure_ascii=False)

    return len(riwayat)  # Kembalikan jumlah total data


async def handle_client(websocket):
    """Tangani koneksi dari satu client (Raspi/dummy)."""
    client_ip = websocket.remote_address[0]
    print(f"\n[+] Client terhubung: {client_ip}")

    try:
        async for message in websocket:
            try:
                data = json.loads(message)

                # Validasi field wajib
                robot_id  = data.get("robot_id", "UNKNOWN")
                status    = data.get("status", "UNKNOWN")
                timestamp = data.get("timestamp", "-")
                confidence = data.get("confidence", 0)

                # Simpan ke file JSON
                total = simpan_json(data)

                # Tampilkan di terminal
                label = "[!!!] KOTOR" if status == "DIRTY" else "[OK]  Bersih"
                print(f"{label} | {robot_id} | conf: {confidence} | {timestamp} | total: {total} data")

                # Kirim respons balik ke client
                respons = {
                    "status"  : "received",
                    "message" : f"Data ke-{total} diterima",
                    "echo"    : status
                }
                await websocket.send(json.dumps(respons))

            except json.JSONDecodeError:
                print(f"[WARNING] Data bukan JSON valid dari {client_ip}")

    except websockets.exceptions.ConnectionClosedOK:
        print(f"[-] Client {client_ip} disconnect normal.")
    except websockets.exceptions.ConnectionClosedError as e:
        print(f"[-] Client {client_ip} disconnect error: {e}")
    except Exception as e:
        print(f"[ERROR] {e}")


async def main():
    print("=" * 50)
    print("  TIFA RECEIVER SERVER")
    print(f"  Listen : {HOST}:{PORT}")
    print(f"  Output : {OUTPUT_PATH}")
    print("=" * 50)
    print("[INFO] Menunggu koneksi dari Raspi...\n")

    async with websockets.serve(handle_client, HOST, PORT):
        await asyncio.Future()  # Jalan terus sampai di-Ctrl+C


if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        print("\n[INFO] Server dihentikan.")