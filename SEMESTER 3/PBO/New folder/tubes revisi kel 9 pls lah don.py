import json

class admin:
    def __init__(self, username, password, bagian):
        self.username = username
        self.password = password
        self.bagian = bagian

class direktur:
    def __init__(self, transaksi_teller, cs_data):
        self.transaksi_teller = transaksi_teller
        self.cs_data = cs_data
        self.keuangan = {}
    
    def lihat_data_transaksi_nasabah(self):
        self.transaksi_teller.tampil_transaksi_nasabah()

    def lihat_laporan_keuangan_bank(self):
        print("Laporan keuangan direktur: ", self.keuangan)

    def lihat_data_customer_service(self):
        print("Data customer service:")
        self.cs_data.tampil_data_nasabah()

    def lihat_data_teller(self, teller_data):
        print("Data teller:")
        teller_data.lihat_data_transaksi_nasabah()

class teller:
    def __init__(self, teller_data, cs_data):
        self.teller_data = teller_data
        self.cs_data = cs_data
    
    def tambah_transaksi_nasabah(self, nasabah, jenis_transaksi, nilai_transaksi):
        self.teller_data.tambah_transaksi_nasabah(nasabah, jenis_transaksi, nilai_transaksi)

    def lihat_data_transaksi_nasabah(self):
        self.teller_data.tampil_transaksi_nasabah()

class customer_service:
    def __init__(self):
        self.data_nasabah = {}
    
    def tambah_data_nasabah(self, nama, saldo):
        self.data_nasabah[nama] = saldo
        print(f"Data nasabah {nama} dengan saldo {saldo} telah ditambahkan oleh customer service.")
        self.tampil_data_nasabah()
        
    def edit_data_nasabah(self, nama, saldo_baru):
        if nama in self.data_nasabah:
            self.data_nasabah[nama] = saldo_baru
            print(f"Data nasabah {nama} telah diperbarui oleh customer service.")
            self.tampil_data_nasabah()
        else:
            print(f"Data nasabah {nama} tidak ada.")
            
    def tampil_data_nasabah(self):
        print("Data nasabah: ", self.data_nasabah)

class user:
    def __init__(self):
        self.users = []

    def save_users_to_file(self):
        with open('acc.json', 'w') as file:
            user_data = [{'username': user.username, 'password': user.password, 'bagian': user.bagian} for user in self.users]
            json.dump(user_data, file)

    def load_users_from_file(self):
        try:
            with open('acc.json', 'r') as file:
                user_data = json.load(file)
                self.users = [admin(data['username'], data['password'], data['bagian']) for data in user_data]
        except FileNotFoundError:
            pass

    def register(self, username, password, bagian):
        if bagian in ["direktur", "teller", "cs"]:
            userbaru = admin(username, password, bagian)
            self.users.append(userbaru)
            print(f"{bagian} dengan nama {username} telah masuk.")
            self.save_users_to_file()
        else:
            print("User tidak ditemukan")

    def login(self, username, password):
        for user in self.users:
            if user.username == username and user.password == password:
                print(f"Login berhasil. Selamat datang, {username}")
                return user
        print("Login gagal. Username atau password salah")
        return None

class TransaksiTeller:
    def __init__(self):
        self.teller_data = {}
    
    def tambah_transaksi_nasabah(self, nasabah, jenis_transaksi, nilai_transaksi):
        if nasabah in self.teller_data:
            self.teller_data[nasabah].append((jenis_transaksi, nilai_transaksi))
        else:
            self.teller_data[nasabah] = [(jenis_transaksi, nilai_transaksi)]

        print(f"Transaksi {jenis_transaksi} sebesar {nilai_transaksi} untuk nasabah {nasabah} telah ditambahkan oleh teller.")
        self.tampil_transaksi_nasabah()

    def tampil_transaksi_nasabah(self):
        print("Data transaksi nasabah:")
        for nasabah, transaksi in self.teller_data.items():
            print(f"Nasabah {nasabah}: {transaksi}")

authenticator = user()
transaksi_teller = TransaksiTeller()
CS = customer_service()
Direktur = direktur(transaksi_teller, CS)
Teller = teller(transaksi_teller, CS)

while True:
    print("=== Bank Application ===")
    print("1. Login")
    print("2. Registrasi")
    print("3. Exit")

    choice_main = input("Pilih menu (1/2/3): ")

    if choice_main == '1':
        username_input = input("Enter your username: ")
        password_input = input("Enter your password: ")

        user_in = authenticator.login(username_input, password_input)

        if user_in:
            if user_in.bagian == "direktur":
                while True:
                    print("a. Lihat Data Transaksi Nasabah")
                    print("b. Lihat Laporan Keuangan Bank")
                    print("c. Lihat Data Customer Service")
                    print("d. Lihat Data Teller")
                    print("e. Logout")
                    choice = input("Pilih menu (a/b/c/d/e): ")

                    if choice == 'a':
                        Direktur.lihat_data_transaksi_nasabah()
                    elif choice == 'b':
                        Direktur.lihat_laporan_keuangan_bank()
                    elif choice == 'c':
                        Direktur.lihat_data_customer_service()
                    elif choice == 'd':
                        Direktur.lihat_data_teller(Teller)
                    elif choice == 'e':
                        break
                    else:
                        print("Pilihan tidak valid")
            elif user_in.bagian == "teller":
                while True:
                    print("a. Lihat Data Transaksi Nasabah")
                    print("b. Tambah Transaksi Nasabah")
                    print("c. Logout")
                    choice = input("Pilih menu (a/b/c): ")

                    if choice == 'a':
                        Teller.lihat_data_transaksi_nasabah()
                    elif choice == 'b':
                        nasabah = input("Masukkan nama nasabah: ")
                        jenis_transaksi = input("Masukkan jenis transaksi (debit/kredit/bunga/biaya administrasi): ")
                        nilai_transaksi = input("Masukkan nilai transaksi: ")
                        Teller.tambah_transaksi_nasabah(nasabah, jenis_transaksi, nilai_transaksi)
                    elif choice == 'c':
                        break
                    else:
                        print("Pilihan tidak valid")
            elif user_in.bagian == "cs":
                while True:
                    print("a. Tambah Data Nasabah")
                    print("b. Edit Data Nasabah")
                    print("c. Tampil Data Nasabah")
                    print("d. Logout")
                    choice = input("Pilih menu (a/b/c/d): ")

                    if choice == 'a':
                        nama = input("Masukkan nama nasabah: ")
                        saldo = input("Masukkan saldo nasabah: ")
                        CS.tambah_data_nasabah(nama, saldo)
                    elif choice == 'b':
                        nama = input("Masukkan nama nasabah yang ingin diubah: ")
                        saldo_baru = input("Masukkan saldo baru: ")
                        CS.edit_data_nasabah(nama, saldo_baru)
                    elif choice == 'c':
                        CS.tampil_data_nasabah()
                    elif choice == 'd':
                        break
                    else:
                        print("Pilihan tidak valid")
            else:
                print("Hanya direktur, teller, dan customer service yang bisa akses.")
        else:
            print("Login gagal. Cek username dan password")
    elif choice_main == '2':
        username_reg = input("Masukkan username: ")
        password_reg = input("Masukkan password: ")
        print("Pilih role:")
        print("1. Direktur")
        print("2. Teller")
        print("3. Customer Service")
        role_reg = input("Pilih role (1/2/3): ")

        if role_reg == '1':
            role_reg = "direktur"
        elif role_reg == '2':
            role_reg = "teller"
        elif role_reg == '3':
            role_reg = "cs"
        else:
            print("Role tidak valid. Registrasi dibatalkan.")
            continue

        authenticator.register(username_reg, password_reg, role_reg)
    elif choice_main == '3':
        print("Exiting the program. Goodbye!")
        authenticator.save_users_to_file()
        break
    else:
        print("Pilihan tidak valid. Silakan pilih kembali.")
