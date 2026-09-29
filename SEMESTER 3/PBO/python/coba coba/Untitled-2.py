class Karyawan:
    def setData(self, depan, belakang, gaji):
        self.first = depan
        self.last = belakang
        self.pay = gaji

    def setEmail(self):
        self.email = self.first + "." + self.last + "@perusahaan.com"


karyawan1 = Karyawan()
karyawan1.setData("kimi", "myardi", 2000)
karyawan1.setEmail()
