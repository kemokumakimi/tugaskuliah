# def load_laporan_keuangan(self):
#         try:
#             with open("laporan_keuangan.txt", "r") as file:
#                 lines = file.readlines()
#                 self.laporan_keuangan = {line.split(':')[0].strip(): int(line.split(':')[1].strip()) for line in lines}
#                 print("Laporan keuangan berhasil dimuat.")
#                 return self.laporan_keuangan
#         except FileNotFoundError:
#             print("File laporan keuangan tidak ditemukan. Membuat file baru.")
#             self.save_laporan_keuangan({
#                 'pendapatan': 0,
#                 'biaya_operasional': 0,
#                 'laba_bersih': 0
#             })
#             return {
#                 'pendapatan': 0,
#                 'biaya_operasional': 0,
#                 'laba_bersih': 0
#             }