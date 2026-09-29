

class Admin:
    def __init__(self, username, password):
        self.__username = username
        self.__password = password
        
        self.data_direktur = []
        self.data_teller = []
        self.data_nasabah = [
    {
        'nama': 'Surya',
        'alamat': 'Jl. Contoh No. 123',
        'transaksi': [
            {"tanggal": "2023-01-15", "jenis": "Transfer Masuk", "jumlah": 5000000, "keterangan": "Dari Rek. 789"},
            {"tanggal": "2023-01-20", "jenis": "Penarikan Tunai", "jumlah": 2000000, "keterangan": "ATM Lokal"},
            {"tanggal": "2023-02-02", "jenis": "Pembayaran Tagihan", "jumlah": 1500000, "keterangan": "Listrik"},
        ],
    },
    {
        'nama': 'Adam',
        'alamat': 'Jl. Test No. 456',
        'transaksi': [
            {"tanggal": "2023-03-10", "jenis": "Transfer Keluar", "jumlah": 3000000, "keterangan": "Ke Rek. 987"},
            {"tanggal": "2023-03-15", "jenis": "Penarikan Tunai", "jumlah": 1000000, "keterangan": "ATM Lokal"},
        ],
    },
    # Tambahkan data nasabah lain jika diperlukan
]



    def login(self):
        maksimal_percobaan = 3
        percobaan = 0

        while percobaan < maksimal_percobaan:
            input_username = input("Username: ")
            input_password = input("Password: ")

            if input_username == self.__username and input_password == self.__password:
                print("Login berhasil sebagai Admin.")
                return True

            else:
                print(f"Login gagal. Sisa percobaan: {maksimal_percobaan - percobaan - 1}")
                percobaan += 1

        print("Batas percobaan login tercapai. Aplikasi keluar.")
        exit()


    def tambah_edit_direktur(self):
        print("1. Tambah Direktur")
        print("2. Edit Direktur")
        pilihan = int(input("Pilih opsi: "))

        if pilihan == 1:
            nama_direktur = input("Masukkan nama direktur: ")
            jabatan_direktur = input("Masukkan jabatan direktur: ")
            self.data_direktur.append({"nama": nama_direktur, "jabatan": jabatan_direktur})
            print("Direktur berhasil ditambahkan.")
        elif pilihan == 2:
            print("Data Direktur:")
            for i, direktur in enumerate(self.data_direktur, start=1):
                print(f"{i}. {direktur['nama']} - {direktur['jabatan']}")

            pilihan_edit = int(input("Pilih direktur yang akan diedit (nomor): "))
            if 1 <= pilihan_edit <= len(self.data_direktur):
                nama_direktur_baru = input("Masukkan nama direktur baru: ")
                jabatan_direktur_baru = input("Masukkan jabatan direktur baru: ")
                self.data_direktur[pilihan_edit - 1] = {"nama": nama_direktur_baru, "jabatan": jabatan_direktur_baru}
                print("Data Direktur berhasil diubah.")
            else:
                print("Nomor direktur tidak valid.")
        else:
            print("Opsi tidak valid.")

    def tambah_edit_teller(self):
        print("1. Tambah Teller")
        print("2. Edit Teller")
        pilihan = int(input("Pilih opsi: "))

        if pilihan == 1:
            self.nama_teller = input("Masukkan nama Teller: ")
            self.cabang_teller = input("Masukkan cabang Teller: ")
            self.data_teller.append({"nama": self.nama_teller, "cabang": self.cabang_teller})
            print("Teller berhasil ditambahkan.")
        elif pilihan == 2:
            print("Data Teller:")
            for i, teller in enumerate(self.data_teller, start=1):
                print(f"{i}. {teller['nama']} - {teller['cabang']}")

            pilihan_edit = int(input("Pilih Teller yang akan diedit (nomor): "))
            if 1 <= pilihan_edit <= len(self.data_teller):
                self.nama_teller_baru = input("Masukkan nama Teller baru: ")
                self.cabang_teller_baru = input("Masukkan cabang Teller baru: ")
                self.data_teller[pilihan_edit - 1] = {"nama": self.nama_teller_baru, "cabang": self.cabang_teller_baru}
                print("Data Teller berhasil diubah.")
            else:
                print("Nomor Teller tidak valid.")
        else:
            print("Opsi tidak valid.")

    def save_data_direktur(self):
        with open("data_direktur.txt", "w") as file:
            for direktur in self.data_direktur:
                file.write(f"{direktur['nama']}|{direktur['jabatan']}\n")

    def save_data_teller(self):
        with open("data_teller.txt", "a") as file:
            for teller in self.data_teller:
                file.write(f"{teller['nama']}|{teller['cabang']}\n")

    def load_data_direktur(self):
        try:
            with open("data_direktur.txt", "r") as file:
                lines = file.readlines()
                self.data_direktur = [{"nama": line.split('|')[0], "jabatan": line.split('|')[1].strip()} for line in lines]
            print("Data direktur berhasil dimuat.")
        except FileNotFoundError:
            print("Data direktur tidak ditemukan.")
            self.data_direktur = []

    def load_data_teller(self):
        try:
            with open("data_teller.txt", "r") as file:
                lines = file.readlines()
                self.data_teller = [{"nama": line.split('|')[0], "cabang": line.split('|')[1].strip()} for line in lines]
            print("Data teller berhasil dimuat.")
        except FileNotFoundError:
            print("Data teller tidak ditemukan.")
            self.data_teller = []

    def save_laporan_keuangan(self, laporan_keuangan):
        with open("laporan_keuangan.txt", "w") as file:
            for key, value in laporan_keuangan.items():
                file.write(f"{key}:{value}\n")

    

class Direktur(Admin):
    def __init__(self, username, password):
        super().__init__(username, password)
        self.data_direktur = [
            {"nama": "Siti", "jabatan": "Direktur Utama"},
            {"nama": "Agung", "jabatan": "Direktur Keuangan"},
        ]
        self.laporan_keuangan = {}
        self.data_teller = []


    def lihat_transaksi_nasabah(self):
        
        print("Data Nasabah:")
        
        for i, nasabah in enumerate(self.data_nasabah, start=1):
            print(f"{i}. {nasabah['nama']} - {nasabah['alamat']}")

        pilihan_nasabah = int(input("Pilih nasabah (nomor): "))
        if 1 <= pilihan_nasabah <= len(self.data_nasabah):
            transaksi_nasabah = self.data_nasabah[pilihan_nasabah - 1].get('transaksi', [])

            print("{:<15} {:<20} {:<15} {:<20}".format("Tanggal", "Jenis Transaksi", "Jumlah (IDR)", "Keterangan"))
            print("-" * 70)

            if transaksi_nasabah:
                for transaksi in transaksi_nasabah:
                    print("{:<15} {:<20} {:<15} {:<20}".format(
                        transaksi['tanggal'],
                        transaksi['jenis'],
                        format(transaksi['jumlah'], ',d'),
                        transaksi['keterangan']
                    ))
            else:
                print("Tidak ada data transaksi untuk nasabah ini.")
                
            print("-" * 70)
        else:
            print("Nomor nasabah tidak valid.")

    def lihat_laporan_keuangan(self):
        self.save_laporan_keuangan()
        self.load_laporan_keuangan()

        print("Laporan Keuangan")
        with open ("laporan_keuangan.txt", "r") as file:
            line = file.readlines()
            print(line)


    def lihat_data_cs(self):
        # Sebagai contoh, kita akan membuat data customer service palsu
        data_cs = [
            {"nama": "CS1", "jabatan": "Customer Service", "cabang": "Cabang A"},
            {"nama": "CS2", "jabatan": "Customer Service", "cabang": "Cabang B"},
        ]

        print("Data Customer Service")
        print("{:<15} {:<20} {:<15}".format("Nama", "Jabatan", "Cabang"))
        print("-" * 50)
        for cs in data_cs:
            print("{:<15} {:<20} {:<15}".format(cs['nama'], cs['jabatan'], cs['cabang']))
        print("-" * 50)

    def save_data_teller(self):
        with open("data_teller.txt", "a") as file:
            for teller in self.data_teller:
                file.write(f"{teller['nama']}|{teller.get('cabang', 'Cabang tidak tersedia')}\n")

    def load_data_teller(self):
        try:
            with open("data_teller.txt", "r") as file:
                lines = file.readlines()
                self.data_teller = [{"nama": line.split('|')[0], "cabang": line.split('|')[1].strip()} for line in lines]
            print("Data teller berhasil dimuat.")
        except FileNotFoundError:
            print("Data teller tidak ditemukan.")
            self.data_teller = []

    def lihat_data_teller(self):
        self.load_data_teller()

        print("Data Teller")
        print("{:<15}  {:<15}".format("Nama", "Cabang"))
        print("-" * 30)
        for teller in self.data_teller:
            print("{:<15}  {:<15}".format(teller['nama'], teller['cabang']))
        print("-" * 30)

    def convert_list_to_dict(self):
    # Assuming self.laporan_keuangan is a list of dictionaries
        self.laporan_keuangan = {item['key']: item['value'] for item in self.laporan_keuangan}

    def save_laporan_keuangan(self):
        # Make sure self.laporan_keuangan is a dictionary
        self.convert_list_to_dict()

        with open("laporan_keuangan.txt", "w") as file:
            for key, value in self.laporan_keuangan.items():
                file.write(f"{key}:{value}\n")

    def load_laporan_keuangan(self):
        try:
            with open("laporan_keuangan.txt", "r") as file:
                lines = file.readlines()
                self.laporan_keuangan = {}
                for line in lines:
                    key, value = line.split(':')
                    self.laporan_keuangan[key.strip()] = int(value.strip())
                print("Laporan keuangan berhasil dimuat.")
                return self.laporan_keuangan
        except FileNotFoundError:
            print("File laporan keuangan tidak ditemukan. Membuat file baru.")
            self.save_laporan_keuangan({
                'pendapatan': 0,
                'biaya_operasional': 0,
                'laba_bersih': 0
            })
            return {
                'pendapatan': 0,
                'biaya_operasional': 0,
                'laba_bersih': 0
            }

class CustomerService(Admin):
    def tambah_edit_nasabah(self):
        print("1. Tambah Nasabah")
        print("2. Edit Nasabah")
        pilihan = int(input("Pilih opsi: "))

        if pilihan == 1:
            nama_nasabah = input("Masukkan nama nasabah: ")
            alamat_nasabah = input("Masukkan alamat nasabah: ")
            self.data_nasabah.append({"nama": nama_nasabah, "alamat": alamat_nasabah})
            print("Nasabah berhasil ditambahkan.")
        elif pilihan == 2:
            print("Data Nasabah:")
            for i, nasabah in enumerate(self.data_nasabah, start=1):
                print(f"{i}. {nasabah['nama']} - {nasabah['alamat']}")

            pilihan_edit = int(input("Pilih nasabah yang akan diedit (nomor): "))
            if 1 <= pilihan_edit <= len(self.data_nasabah):
                nama_nasabah_baru = input("Masukkan nama nasabah baru: ")
                alamat_nasabah_baru = input("Masukkan alamat nasabah baru: ")
                self.data_nasabah[pilihan_edit - 1] = {"nama": nama_nasabah_baru, "alamat": alamat_nasabah_baru}
                print("Data Nasabah berhasil diubah.")
            else:
                print("Nomor nasabah tidak valid.")
        else:
            print("Opsi tidak valid.")

    def save_data_nasabah(self):
        with open("data_nasabah.txt", "w") as file:
            for nasabah in self.data_nasabah:
                file.write(f"{nasabah['nama']}|{nasabah['alamat']}\n")

    
    

class Teller(Admin):
    def tambah_transaksi_nasabah(self):
        print("1. Debit")
        print("2. Kredit")
        print("3. Bunga")
        print("4. Biaya Administrasi")
        pilihan = int(input("Pilih jenis transaksi: "))

        print("Data Nasabah:")
        for i, nasabah in enumerate(self.data_nasabah, start=1):
            print(f"{i}. {nasabah['nama']} - {nasabah['alamat']} - Saldo: {nasabah.get('saldo', 0)}")

        pilihan_nasabah = int(input("Pilih nasabah (nomor): "))
        if 1 <= pilihan_nasabah <= len(self.data_nasabah):
            jumlah_transaksi = int(input("Masukkan jumlah transaksi: "))

            # Periksa apakah 'transaksi' sudah ada dalam nasabah atau belum
            if 'transaksi' not in self.data_nasabah[pilihan_nasabah - 1]:
                self.data_nasabah[pilihan_nasabah - 1]['transaksi'] = []

            if pilihan == 1:
                # Debit
                self.data_nasabah[pilihan_nasabah - 1]['transaksi'].append({
                    "tanggal": "tanggal_debit",  # Anda perlu menambahkan tanggal transaksi debit
                    "jenis": "Debit",
                    "jumlah": jumlah_transaksi,
                    "keterangan": "Debit"
                })
                self.data_nasabah[pilihan_nasabah - 1]['saldo'] -= jumlah_transaksi
                print("Transaksi Debit berhasil.")
            elif pilihan == 2:
                # Kredit
                self.data_nasabah[pilihan_nasabah - 1]['transaksi'].append({
                    "tanggal": "tanggal_kredit",  # Anda perlu menambahkan tanggal transaksi kredit
                    "jenis": "Kredit",
                    "jumlah": jumlah_transaksi,
                    "keterangan": "Kredit"
                })
                self.data_nasabah[pilihan_nasabah - 1]['saldo'] += jumlah_transaksi
                print("Transaksi Kredit berhasil.")
            elif pilihan == 3:
                # Bunga
                bunga = 0.05  # Misalnya, bunga sebesar 5%
                bunga_amount = int(jumlah_transaksi * bunga)
                self.data_nasabah[pilihan_nasabah - 1]['transaksi'].append({
                    "tanggal": "tanggal_bunga",  # Anda perlu menambahkan tanggal transaksi bunga
                    "jenis": "Bunga",
                    "jumlah": bunga_amount,
                    "keterangan": "Bunga"
                })
                self.data_nasabah[pilihan_nasabah - 1]['saldo'] += jumlah_transaksi + bunga_amount
                print("Transaksi Bunga berhasil.")
            elif pilihan == 4:
                # Biaya Administrasi
                biaya_administrasi = 10000  # Misalnya, biaya administrasi sebesar 10,000
                self.data_nasabah[pilihan_nasabah - 1]['transaksi'].append({
                    "tanggal": "tanggal_biaya_administrasi",  # Anda perlu menambahkan tanggal transaksi biaya administrasi
                    "jenis": "Biaya Administrasi",
                    "jumlah": biaya_administrasi,
                    "keterangan": "Biaya Administrasi"
                })
                self.data_nasabah[pilihan_nasabah - 1]['saldo'] -= biaya_administrasi
                print("Transaksi Biaya Administrasi berhasil.")
            else:
                print("Jenis transaksi tidak valid.")
        else:
            print("Nomor nasabah tidak valid.")

    def save_data_transaksi_nasabah(self):
        with open("data_transaksi_nasabah.txt", "w") as file:
            for transaksi_nasabah in self.data_nasabah:
                file.write(f"{transaksi_nasabah['nama']}\n{transaksi_nasabah['transaksi']}\n")

    def lihat_transaksi_nasabah(self):
        print("Data Nasabah:")

        for i, nasabah in enumerate(self.data_nasabah, start=1):
            print(f"{i}. {nasabah['nama']} - {nasabah['alamat']}")

        pilihan_nasabah = int(input("Pilih nasabah (nomor): "))
        if 1 <= pilihan_nasabah <= len(self.data_nasabah):
            transaksi_nasabah = self.data_nasabah[pilihan_nasabah - 1]['transaksi']

            # Tambahkan logika ini untuk memeriksa apakah 'transaksi' ada di dalam nasabah
            if 'transaksi' in self.data_nasabah[pilihan_nasabah - 1]:
                transaksi_nasabah = self.data_nasabah[pilihan_nasabah - 1]['transaksi']

                print("{:<15} {:<20} {:<15} {:<20}".format("Tanggal", "Jenis Transaksi", "Jumlah (IDR)", "Keterangan"))
                print("-" * 70)

                if transaksi_nasabah:
                    for transaksi in transaksi_nasabah:
                        print("{:<15} {:<20} {:<15} {:<20}".format(
                            transaksi['tanggal'],
                            transaksi['jenis'],
                            format(transaksi['jumlah'], ',d'),
                            transaksi['keterangan']
                        ))
                else:
                    print("Tidak ada data transaksi untuk nasabah ini.")

                print("-" * 70)
            else:
                print("Tidak ada data transaksi untuk nasabah ini.")
        else:
            print("Nomor nasabah tidak valid.")

    def load_data_nasabah(self):
        try:
            with open("data_nasabah.txt", "r") as file:
                lines = file.readlines()
                self.data_nasabah = [{"nama": line.split('|')[0], "alamat": line.split('|')[1].strip()} for line in lines]
            print("Data nasabah berhasil dimuat.")
        except FileNotFoundError:
            print("Data nasabah tidak ditemukan.")
            self.data_nasabah = []

    def load_data_transaksi_nasabah(self):
        try:
            with open("data_transaksi_nasabah.txt", "r") as file:
                lines = file.readlines()
                self.data_nasabah = [{"transaksi": line.split('|')[0]} for line in lines]
            print("Data transaksi nasabah berhasil dimuat.")
        except FileNotFoundError:
            print("Data transaksi nasabah tidak ditemukan.")
            self.data_nasabah = []



# Inisialisasi admin dan direktur dan teller dan cs
admin = Admin("admin", "password123")
direktur = Direktur("direktur", "password456")
teller = Teller("teller", "password123")
cs = CustomerService("cs", "password123")
direktur.save_laporan_keuangan({
    'pendapatan': 1000000,
    'biaya_operasional': 500000,
    'laba_bersih': 500000
})


while True:
    print("Selamat Datang Di Aplikasi Perbankan")
    pilihan = int(input('''1. Admin
2. Direktur
3. Customer Service
4. Teller 
5. Quit

Input: '''))

    if pilihan == 1:
        if admin.login():
            print("1. Menambah/Mengedit data direktur")
            print("2. Menambah/Mengedit data teller", end="")  
            pilihan = int(input("\nPilih opsi: "))  
            if pilihan == 1:
                # Menambah/Mengedit data direktur
                admin.tambah_edit_direktur()
                # Simpan perubahan ke file
                admin.save_data_direktur()
            elif pilihan == 2:
                # Menambah/Mengedit data teller
                admin.tambah_edit_teller()
                # Simpan perubahan ke file
                admin.save_data_teller()



    elif pilihan == 2:
        pilihanDirektur = int(input('''1. Melihat data transaksi keuangan nasabah
2. Melihat laporan keuangan bank
3. Melihat data customer service
4. Melihat data teller
input: '''))

        if pilihanDirektur == 1:
            teller.lihat_transaksi_nasabah()
        elif pilihanDirektur == 2:
            direktur.lihat_laporan_keuangan()
        elif pilihanDirektur == 3:
            direktur.lihat_data_cs()
        elif pilihanDirektur == 4:
            direktur.lihat_data_teller()
            # admin.save_data_teller()

    elif pilihan == 3:
        print("Menambah/Mengedit data nasabah")
        cs.tambah_edit_nasabah()
        cs.save_data_nasabah()

    elif pilihan == 4:
        pilihanTeller = int(input('''1. Menambah transaksi nasabah (debit/kredit/bunga/biaya administrasi)
2. Melihat data transaksi nasabah
input: '''))
        if pilihanTeller == 1:
            teller.tambah_transaksi_nasabah()
            teller.save_data_transaksi_nasabah()
        elif pilihanTeller == 2:
            teller.lihat_transaksi_nasabah()
    elif pilihan == 5:
        # Simpan data direktur dan laporan keuangan ke file sebelum keluar
        admin.save_laporan_keuangan(direktur.laporan_keuangan)
        print('Terima Kasih telah menggunakan Program ini...')
        break

