Mahasiswa = {}


def inputdatamahasiswa():
    jumlah_mahasiswa = int(input("Masukkan Jumlah Mahasiswa: "))

    for i in range(jumlah_mahasiswa):

        print(f"Data Mahasiswa ke-{i+1}:")
        nama = input("Nama      : ")
        nim = int(input("NIM       : "))
        prodi = input("Prodi     : ")
        nilaiUts = int(input("Nilai UTS : "))
        nilaiUas = int(input("Nilai UAS : "))


        Mahasiswa[i] = {
            "Nama": nama,
            "Nim": nim,
            "Prodi": prodi,
            "Nilai UTS": nilaiUts,
            "Nilai UAS": nilaiUas,
        }


def menampilkanrata():
    nilaiRata = (nilaiUas + nilaiUts) / 2

    for i, mahasiswa in Mahasiswa.items():
        Mahasiswa[i] = {
            "Nama": nama,
            "Nim": nim,
            "Prodi": prodi,
            "Nilai UTS": nilaiUts,
            "Nilai UAS": nilaiUas,
        }

        print(f"NIM             : {mahasiswa['Nim']}")
        print(f"Nama            : {mahasiswa['Nama']}")
        print(f"Prodi           : {mahasiswa['Prodi']}")
        print(f"Nilai Rata-Rata : {mahasiswa['Nilai Rata-Rata']}")
        print("-" * 30)

    

def menampilkanSemua():
    print("\nData Mahasiswa: ")
    for i, mahasiswa in Mahasiswa.items():
        print(f"NIM             : {mahasiswa['Nim']}")
        print(f"Nama            : {mahasiswa['Nama']}")
        print(f"Prodi           : {mahasiswa['Prodi']}")
        print(f"Nilai UTS       : {mahasiswa['Nilai UTS']}")
        print(f"Nilai UAS       : {mahasiswa['Nilai UAS']}")
        print(f"Nilai Rata-Rata : {mahasiswa['Nilai Rata-Rata']}")
        print("-" * 30)

def carinim():
    cari = int(input("cari nim: "))
    for i in Mahasiswa.items():
        if cari == {i['Nim']}:
                print(f"NIM             : {i['Nim']}")
                print(f"Nama            : {i['Nama']}")
                print(f"Prodi           : {i['Prodi']}")
                print(f"Nilai UTS       : {i['Nilai UTS']}")
                print(f"Nilai UAS       : {i['Nilai UAS']}")
                print(f"Nilai Rata-Rata : {i['Nilai Rata-Rata']}")
                print("-" * 30)

while True:
    pilihan = int(input("pilih apa yang ingin ditampilkan: "))
    if pilihan == 1:
        inputdatamahasiswa()
    elif pilihan == 2:
        menampilkanrata()
    elif pilihan == 3:
        menampilkanSemua(Mahasiswa)
    elif pilihan == 4:
        carinim(Mahasiswa)
    elif pilihan == 0:
        break
