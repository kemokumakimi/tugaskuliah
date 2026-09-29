import socket
import json

# KONFIGURASI
UDP_IP = "127.0.0.1"
UDP_PORT = 5005

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print(f"--- ROS DUMMY LISTENER ---")
print(f"Mendengarkan sinyal TIFA di {UDP_IP}:{UDP_PORT}...")

try:
    while True:
        data, addr = sock.recvfrom(4096)
        try:
            payload = json.loads(data.decode())
            print(f"\n[RECEIVE] Dari: {addr}")
            print(f"  Timestamp   : {payload.get('timestamp')}")
            print(f"  Status Meja : {payload.get('table_status')}")
            print(f"  Goal Signal : {payload.get('goal_signal')}")
            print(f"  Objects Found: {len(payload.get('raw_predictions', []))}")
            
            # Print detail object jika ada
            for obj in payload.get('raw_predictions', []):
                print(f"    - {obj['class']} (conf: {obj['confidence']:.2f})")
                
        except Exception as e:
            print(f"[ERROR] Gagal parse data: {e}")
except KeyboardInterrupt:
    print("\n[INFO] Listener dihentikan.")
finally:
    sock.close()
