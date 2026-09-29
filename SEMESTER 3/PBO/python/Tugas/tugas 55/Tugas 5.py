# def inputwaktu():
#     jamAwal = int(input("Masukkan Awal Jam: "))
#     menitAwal = int(input("Masukkan Awal Menit: "))
#     detikAwal = int(input("Masukkan Awal Detik: "))

#     if jamAwal > 24:
#         print("tidak valid")

#     if menitAwal >= 61:
#         print("tidak valid")

#     if detikAwal >= 61:
#         print("tidak valid")

#     jamAkhir = int(input("Masukkan Akhir jam: "))
#     menitAkhir = int(input("Masukkan Akhir Menit: "))
#     detikAkhir = int(input("Masukkan Akhir Detik: "))

#     if jamAkhir > 24:
#         print("tidak valid")

#     if menitAkhir >= 61:
#         print("tidak valid")

#     if detikAkhir >= 61:
#         print("tidak valid")

#     if detikAwal > detikAkhir:
#         menitAwal -= 1
#         detik = (60 - detikAwal) + detikAkhir
#     else:
#         detik = detikAkhir - detikAwal

#     if menitAwal > menitAkhir:
#         jamAwal -= 1
#         menit = (60 - menitAwal) + menitAkhir
#     else:
#         menit = menitAkhir - menitAwal

#     if jamAwal > jamAkhir:
#         jam = (24 - jamAwal) + jamAkhir
#     else:
#         jam = jamAkhir - jamAwal

#     print("kita ngobrol selama")
#     print(f"{jam}:{menit}:{detik}")


# while True:
#     print("Selamat datang di Program...")
#     pilihan = int(input("keluar tekan 0: "))
#     if pilihan == 0:
#         break
#     inputwaktu()


# # Masukkan waktu awal dan waktu akhir dalam format 'HH:MM:SS'
# waktu_awal = input("Masukkan waktu awal (HH:MM:SS): ")
# waktu_akhir = input("Masukkan waktu akhir (HH:MM:SS): ")

# # Pisahkan jam, menit, dan detik dari input
# jam_awal, menit_awal, detik_awal = map(int, waktu_awal.split(':'))
# jam_akhir, menit_akhir, detik_akhir = map(int, waktu_akhir.split(':'))

# # Hitung selisih jam, menit, dan detik
# selisih_jam = jam_akhir - jam_awal
# selisih_menit = menit_akhir - menit_awal
# selisih_detik = detik_akhir - detik_awal

# # Handle jika selisih detik negatif
# if selisih_detik < 0:
#     selisih_menit -= 1
#     selisih_detik += 60

# # Handle jika selisih menit negatif
# if selisih_menit < 0:
#     selisih_jam -= 1
#     selisih_menit += 60

# print(f"Durasi: {selisih_jam} jam {selisih_menit} menit {selisih_detik} detik")

print("kimi")
