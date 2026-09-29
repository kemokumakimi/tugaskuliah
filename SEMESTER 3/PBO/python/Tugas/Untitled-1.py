class Polygon:
    def __init__(self, sides):
        self.sides = sides

    def get_number_of_sides(self):
        return self.sides

    def get_perimeter(self):
        return sum(self.sides)

    def get_area(self):
        pass  # Metode ini akan diimplementasikan oleh kelas turunan


class Square(Polygon):
    def __init__(self, sisi):
        if self.is_valid_square(sisi):
            super().__init__([sisi, sisi, sisi, sisi])
        else:
            print("Panjang sisi tidak memenuhi kriteria sebagai persegi")

    def is_valid_square(self, sisi):
        return sisi > 0

    def get_area(self):
        return self.sides[0] ** 2


class Rectangle(Polygon):
    def __init__(self, panjang, lebar):
        if self.is_valid_rectangle(panjang, lebar):
            super().__init__([panjang, lebar, panjang, lebar])
        else:
            print("Panjang dan lebar tidak memenuhi kriteria sebagai persegi panjang")

    def is_valid_rectangle(self, panjang, lebar):
        return panjang > 0 and lebar > 0

    def get_area(self):
        return self.sides[0] * self.sides[1]


# Contoh penggunaan:
panjang_sisi_persegi = float(input("Masukkan panjang sisi persegi: "))
persegi = Square(panjang_sisi_persegi)
if persegi.get_number_of_sides():
    print("Keliling Persegi:", persegi.get_perimeter())
    print("Luas Persegi:", persegi.get_area())

panjang_persegi_panjang = float(input("Masukkan panjang persegi panjang: "))
lebar_persegi_panjang = float(input("Masukkan lebar persegi panjang: "))
persegi_panjang = Rectangle(panjang_persegi_panjang, lebar_persegi_panjang)
if persegi_panjang.get_number_of_sides():
    print("Keliling Persegi Panjang:", persegi_panjang.get_perimeter())
    print("Luas Persegi Panjang:", persegi_panjang.get_area())
