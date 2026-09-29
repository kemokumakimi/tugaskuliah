class bidangDatar:
    def __init__ (self,persegipanjang, bujur, lingkaran):
        self.persegipanjang = persegipanjang
        self.bujur = bujur
        self.lingkaran = lingkaran
        
class persegipanjang():
    def __init__(self, p, l):
        self.p = p
        self.l = l
            
    def rumus(self):
        self.luas = self.p * self.l
        self.keliling = (2 * self.p) + (2 * self.l)
        print(f"Luas adalah     : {self.luas}")
        print(f"Keliling adalah : {self.keliling}")

class bujur():
    def __init__(self, sisi):
        self.sisi = sisi

    def rumus(self):
        self.luas = self.sisi * self.sisi
        self.keliling = 4 * self.sisi
        print(f"Luas adalah     : {self.luas}")
        print(f"Keliling adalah : {self.keliling}")

class lingkaran():
    def __init__(self, jari):
        self.jari = jari

    def rumus(self):
        self.luas = 3.14 * (self.jari * self.jari)
        self.keliling = 2 * 3.14 * self.jari
        print(f"Luas adalah     : {self.luas}")
        print(f"Keliling adalah : {self.keliling}")


while True:
    print("")
    print("")
    print("Menu Bidang Datar: ")
    print('1. Persegi Panjang')
    print('2. Bujur')
    print('3. Lingkaran')
    print('4. Quit ')

    pilihan = int(input("Masukkan Pilihan (1/2/3): "))

    if pilihan == 1:
        panjang = int(input("Masukkan Panjang: "))
        lebar = int(input("Masukkan Lebar: "))
        persegipanjang = persegipanjang(panjang,lebar)
        persegipanjang.rumus()
    elif pilihan == 2:
        sisi = int(input("Masukkan Sisi: "))
        bujur = bujur(sisi)
        bujur.rumus()
    elif pilihan == 3:
        jari = int(input("Masukkan Jari-Jari: "))
        lingkaran = lingkaran(jari)
        lingkaran.rumus()
    elif pilihan == 4:
        break
        