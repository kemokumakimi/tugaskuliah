class Admin:
    def __init__(self, username, password):
        self.username = username
        self.password = password

    def login(self):
        # Implementasi login admin
        pass

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

    def tambah_edit_teller(self, data_teller):
        # Menambah atau mengedit data teller
        pass

class Direktur(Admin):
    def __init__(self, username, password):
        super().__init__(username, password)
        self.laporan_keuangan = {
            'pendapatan': 10000000,
            'biaya_operasional': 5000000,
            'laba_bersih': 5000000
        }
        self.data_direktur = [
            {"nama": "John Doe", "jabatan": "Direktur Utama"},
            {"nama": "Jane Smith", "jabatan": "Direktur Keuangan"},
        ]

    def lihat_transaksi_nasabah(self, id_nasabah):
        # Sebagai contoh, kita akan membuat data transaksi palsu untuk nasabah dengan id tertentu
        transaksi_nasabah = {
            123: [
                {"tanggal": "2023-01-15", "jenis": "Transfer Masuk", "jumlah": 5000000, "keterangan": "Dari Rek. 789"},
                {"tanggal": "2023-01-20", "jenis": "Penarikan Tunai", "jumlah": 2000000, "keterangan": "ATM Lokal"},
                {"tanggal": "2023-02-02", "jenis": "Pembayaran Tagihan", "jumlah": 1500000, "keterangan": "Listrik"},
            ],
            # Tambahkan data transaksi untuk nasabah lain jika diperlukan
        }

        if id_nasabah in transaksi_nasabah:
            transaksi_nasabah_nasabah = transaksi_nasabah[id_nasabah]
            print("{:<15} {:<20} {:<15} {:<20}".format("Tanggal", "Jenis Transaksi", "Jumlah (IDR)", "Keterangan"))
            print("-" * 70)
            for transaksi in transaksi_nasabah_nasabah:
                print("{:<15} {:<20} {:<15} {:<20}".format(
                    transaksi['tanggal'],
                    transaksi['jenis'],
                    format(transaksi['jumlah'], ',d'),
                    transaksi['keterangan']
                ))
            print("-" * 70)
        else:
            print(f"Tidak ada data transaksi untuk nasabah dengan ID {id_nasabah}")

    def lihat_laporan_keuangan(self):
        print("Laporan Keuangan Bank")
        print("-" * 30)
        print("Pendapatan           : IDR", format(self.laporan_keuangan['pendapatan'], ',d'))
        print("Biaya Operasional    : IDR", format(self.laporan_keuangan['biaya_operasional'], ',d'))
        print("Laba Bersih          : IDR", format(self.laporan_keuangan['laba_bersih'], ',d'))
        print("-" * 30)

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

    def lihat_data_teller(self):
        # Sebagai contoh, kita akan membuat data teller palsu
        data_teller = [
            {"nama": "Teller1", "jabatan": "Teller", "cabang": "Cabang A"},
            {"nama": "Teller2", "jabatan": "Teller", "cabang": "Cabang B"},
        ]

        print("Data Teller")
        print("{:<15} {:<20} {:<15}".format("Nama", "Jabatan", "Cabang"))
        print("-" * 50)
        for teller in data_teller:
            print("{:<15} {:<20} {:<15}".format(teller['nama'], teller['jabatan'], teller['cabang']))
        print("-" * 50)

class CustomerService(Admin):
    def tambah_edit_nasabah(self, data_nasabah):
        # Menambah atau mengedit data nasabah
        pass

class Teller(Admin):
    def tambah_transaksi_nasabah(self, id_nasabah, jenis_transaksi, jumlah):
        # Menambah transaksi nasabah (debit/kredit/bunga/biaya administrasi)
        pass

    def lihat_transaksi_nasabah(self, id_nasabah):
        # Melihat data transaksi nasabah
        pass


admin = Admin("admin", "password123")
direktur = Direktur("direktur", "password456")


while True:
    print("Selamat Datang Di Aplikasi Perbankan")
    pilihan = int(input('''1. Admin
2. Direktur
3. Customer Service
4. Teller 
5. Quit

Input: '''))

    

    if pilihan == 1:
        pilihanAdmin = int(input('''1. Login ke dalam Aplikasi
2. Menambah/Mengedit data direktur
3. Menambah/Mengedit data teller
input: '''))
        if pilihanAdmin == 1:
            admin.login()
        elif pilihanAdmin == 2:
            # Menambah/Mengedit data direktur
            direktur = Direktur("direktur", "password456")
            direktur.tambah_edit_direktur()
        elif pilihanAdmin == 3:
            # Menambah/Mengedit data teller
            pass
        
    elif pilihan == 2:
        pilihanDirektur = int(input('''1. Melihat data transaksi keuangan nasabah
2. Melihat laporan keuangan bank
3. Melihat data customer service
4. Melihat data teller
input: '''))
        
        if pilihanDirektur == 1:
            direktur.lihat_transaksi_nasabah(123)
        elif pilihanDirektur == 2:
            direktur.lihat_laporan_keuangan()
        elif pilihanDirektur == 3:
            direktur.lihat_data_cs()
        elif pilihanDirektur == 4:
            direktur.lihat_data_teller()

    elif pilihan == 3:
        print("Menambah/Mengedit data nasabah")
    elif pilihan == 4:
        pilihanTeller = int(input('''1. Menambah transaksi (debit/kredit/bunga/biaya administrasi)
2. Melihat data transaksi nasabah
input: '''))
        if pilihanTeller == 1:
            pass
        elif pilihanTeller == 2:
            pass
    elif pilihan == 5:
        print('Terima Kasih telah menggunakan Program ini...')
        break
