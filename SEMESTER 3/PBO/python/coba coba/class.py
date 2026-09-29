class lingkaran:
    def __init__(self, r):
        self.jari = r
    
    # def setData(self,jariluas,jarikeliling):
    #     self.jariluas = jariluas
    #     self.jarikeliling =jarikeliling

    def luas(self, r):
        # self.luas = 3.14 * (self.jariluas * self.jariluas)
        self.luas = 3.14 * (r * r)
        print(self.luas)
    
    def keliling(self, r):
        # self.keliling = 2 * 3.14 * self.jarikeliling
        self.keliling =2 * 3.14 * r
        print(self.keliling)


ling = lingkaran(7)
# ling.setData(7,10)
ling.luas(12)
ling.keliling(7)
print(ling.jari)