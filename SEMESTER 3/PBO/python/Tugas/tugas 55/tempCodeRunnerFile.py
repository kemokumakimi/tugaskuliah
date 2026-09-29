def inputwaktu():
    jamAwal = int(input("Masukkan Awal Jam: "))
    menitAwal = int(input("Masukkan Awal Menit: "))
    detikAwal = int(input("Masukkan Awal Detik: "))
    
    if jamAwal > 24:
        print("tidak valid")

    if menitAwal >= 61:
        print("tidak valid")
    
    if detikAwal >= 61:
        print("tidak valid")

    jamAkhir = int(input("Masukkan Akhir jam: "))
    menitAkhir = int(input("Masukkan Akhir Menit: "))
    detikAkhir = int(input("Masukkan Akhir Detik: "))

    if jamAkhir > 24:
        print("tidak valid")

    if menitAkhir >= 61:
        print("tidak valid")
    
    if detikAkhir >= 61:
        print("tidak valid")

    if detikAwal > detikAkhir:
        menitAwal -= 1
        detik = (60 - detikAwal) + detikAkhir
    else:
        detik = detikAkhir - detikAwal
    
    if menitAwal > menitAkhir:
        jamAwal -= 1
        menit = (60 - menitAwal) + menitAkhir
    else: 
        menit = menitAkhir - menitAwal

    if jamAwal > jamAkhir:
        jam = (24 - jamAwal) + jamAkhir 
    else:
        jam = jamAkhir - jamAwal

    print("kita ngobrol selama")
    print(f"{jam}:{menit}:{detik}")



while True:
    print("Selamat datang di Program...")
    pilihan = int(input("keluar tekan 0: "))
    if pilihan == 0:
        break
    inputwaktu()

