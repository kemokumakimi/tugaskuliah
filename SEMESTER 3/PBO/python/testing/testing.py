# Fungsi untuk memasukkan data awal mahasiswa
def masukkan_data_awal():
    data_mahasiswa = {}
    jumlah_data = int(input("Masukkan jumlah data awal mahasiswa: "))
    
    for i in range(jumlah_data):
        print(f"Masukkan data mahasiswa ke-{i + 1}:")
        nama = input("Nama: ")
        nim = input("NIM: ")
        uts = float(input("Nilai UTS: "))
        uas = float(input("Nilai UAS: "))
        data_mahasiswa[nim] = {
            "Nama": nama,
            "NIM": nim,
            "Nilai UTS": uts,
            "Nilai UAS": uas
        }
    
    return data_mahasiswa

# Fungsi untuk menambahkan data mahasiswa tambahan
def tambahkan_data_tambahan(data_mahasiswa):
    print("Masukkan data mahasiswa tambahan:")
    nim = input("NIM: ")
    nama = input("Nama: ")
    uts = float(input("Nilai UTS: "))
    uas = float(input("Nilai UAS: "))
    data_mahasiswa[nim] = {
        "Nama": nama,
        "NIM": nim,
        "Nilai UTS": uts,
        "Nilai UAS": uas
    }

# Fungsi untuk menuliskan data mahasiswa ke dalam file .txt
def tulis_data_ke_file(data_mahasiswa):
    with open("data Mahasiswwa.txt", "a") as file:
        for nim, mahasiswa in data_mahasiswa.items():
            file.write(f"{mahasiswa['Nama']}, {mahasiswa['NIM']}, {mahasiswa['Nilai UTS']}, {mahasiswa['Nilai UAS']}\n")

# Fungsi utama
def main():
    data_mahasiswa = {}
    while True:
        print("Menu:")
        print("1. Masukkan data awal mahasiswa")
        print("2. Tambahkan data mahasiswa tambahan")
        print("3. Keluar")
        pilihan = input("Pilih menu: ")

        if pilihan == "1":
            data_mahasiswa.update(masukkan_data_awal())
        elif pilihan == "2":
            tambahkan_data_tambahan(data_mahasiswa)
        elif pilihan == "3":
            tulis_data_ke_file(data_mahasiswa)
            print("Data telah ditulis ke dalam file data_mahasiswa.txt")
            break
        else:
            print("Pilihan tidak valid. Silakan pilih menu yang benar.")

if __name__ == "__main__":
    main()
