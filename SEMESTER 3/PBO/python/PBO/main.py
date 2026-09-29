# import time

# jumlah_data = int(input("masukkan jumlah data: "))
# jumlah_nilai = 0

# for i in range(1,jumlah_data+1):

#     nilai = int(input(f"nilai {i}:"))
#     jumlah_nilai += nilai
#     rata_rata = jumlah_nilai / i
# print("jumlah nilai adalah: ", jumlah_nilai)
# print(f"rata-rata nilai adalah:{rata_rata}")

# import time

# for i in reversed(range(1, 4)):
#     time.sleep(1)
#     print(i)

# time.sleep(1)
# print("happy birthday!!")

# a = 0
# while a <= 10:
#     print("kimi")
#     a += 1

# nama = input("masukkan nama:")
# n = int(input("mau diulang berapa kali?"))

# a = 0
# while a < n:
#     print(nama)
#     a += 1
# jawaban = "ya"
# while jawaban == "ya":
#     jawab = int(input("mau berapa baris: "))
#     a = 1
#     while (a < jawab + 1):
#         i = 0
#         while (i < a):
#             print("*", end="  ")
#             i += 1
#         print()
#         a = a + 1
#     jawaban = input("masih mau lanjut?(ya/tidak)")

# print("program end")
# n = int(input("masukkan banyak data: "))
# i = 0
# jumlah = 0
# while (i < n):
#     i += 1
#     nilai = int(input(f"nilai ke-{i}: "))
#     jumlah += nilai


# class Tiket:
#     def __init__(self, harga):
#         self.harga = harga

#     def total(self, tiket):
#         total = self.harga*tiket
#         print(total)
        
# class Pembeli:
#     def __init__(self, tiket):
#         self.tiket = tiket

#     def tampilkan_total(self):
#         harga_tiket = 45000 
#         total = self.tiket*harga_tiket
#         print(f"Total untuk {self.tiket} tiket adalah: Rp {total}")


# beli = Tiket(5)
# beli.total(5)

# bayar = Pembeli(5)
# bayar.tampilkan_total()


