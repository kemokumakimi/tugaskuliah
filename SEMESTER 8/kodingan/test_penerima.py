import socket

# Buka port 5005 untuk mendengarkan kiriman dari luar
UDP_IP = "192.168.100.92"
UDP_PORT = 5005

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print(f"Server penerima aktif di Port {UDP_PORT}. Silakan jalankan tifa_win_ai.py di Windows...")

while True:
    # Tunggu data masuk (maksimal 1024 byte)
    data, addr = sock.recvfrom(1024)
    print(f"[BERHASIL] Menerima data dari Laptop Windows ({addr[0]}): {data.decode()}")
