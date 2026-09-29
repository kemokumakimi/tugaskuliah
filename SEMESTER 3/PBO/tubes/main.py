import random

angkarandom = random.randint(1,20)

print("Tebak angka dari 1 - 20: ")
angka = 0
banyakpercobaan = 0

while angkarandom != angka:
    angka = int(input(""))
    if angkarandom > angka:
        print("Angka yang kamu tebak terlalu kecil. Coba lagi ")
    elif angkarandom < angka:
        print("Angka yang kamu tebak terlalu besar. Coba lagi")
    elif angkarandom == angka:
        print("Sip. tebakan kamu benar!")
    banyakpercobaan += 1
    
print("Banyak percobaan: ",banyakpercobaan)



