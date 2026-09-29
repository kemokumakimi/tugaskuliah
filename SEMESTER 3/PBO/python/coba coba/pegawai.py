class pegawai:
    def __init__(self, nama, divisi, gaji):
        self.nama = nama
        self.divisi = divisi
        self.gaji = gaji

    def cekNama(self):
        print(f"Nama Pegawai: {self.nama}")

    def cekAtribut(self):
        print(self.nama)
        print(self.divisi)
        print(self.gaji)


peg1 = pegawai("kimi", "sdm", 5000)
peg1.cekAtribut()