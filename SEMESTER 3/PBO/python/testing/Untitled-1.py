# #create
# import mysql.connector

# db = mysql.connector.connect(
#     host = "localhost",
#     user = "root",
#     password = "",
#     database = "seantuy"
# )


# real = db.cursor()
# table_content = '''CREATE TABLE teman_saya (
#     no_teman INT AUTO_INCREMENT PRIMARY KEY,
#     nama VARCHAR(255),
#     nim VARCHAR(255),
# )
# '''

# real.execute(table_content)
# print("Table Created")

# # # read
# # import mysql.connector

# # db =mysql.connector.connect(
# #     host = "localhost",
# #     user = "root",
# #     password = "",
# #     database = "seantuy"
# # )


# # real = db.cursor()
# # real.execute("SELECT * FROM data_mahasiswa")

# # data = real.fetchall()

# # for x in data:
# #     print(x)

# # update
# # import mysql.connector

# # db =mysql.connector.connect(
# #     host = "localhost",
# #     user = "root",
# #     password = "",
# #     database = "seantuy"
# # )


# # real = db.cursor()

# # ubah = "UPDATE data_mahasiswa SET nama = %s, nim = %s, kelas = %s WHERE nama = %s"
# # data_ubah = ("Daffa", "110322190", "TK4607", "Yusuf")
# # real.execute(ubah, data_ubah)

# # db.commit()

# # real.execute("SELECT * FROM data_mahasiswa")
# # data = real.fetchall()

# # for x in data:
# #     print(x)

# # #delete
# # import mysql.connector

# # db =mysql.connector.connect(
# #     host = "localhost",
# #     user = "root",
# #     password = "",
# #     database = "seantuy"
# # )


# # real = db.cursor()

# # data_delete = "DELETE FROM data_mahasiswa WHERE no_mhs = %s"
# # val = (2,)
# # real.execute(data_delete, val)

# # db.commit()

# # real.execute("SELECT * FROM data_mahasiswa")
# # data = real.fetchall()

# # for x in data:
# #     print(x)

# # import mysql.connector

# # db =mysql.connector.connect(
# #     host = "localhost",
# #     user = "root",
# #     password = "",
# #     database = "seantuy"
# # )


# # real = db.cursor()
# # nama_tabel = input("Masukkan nama tabel: ")
# # jawaban = input("apakah anda yakin ingin menghapus {nama_tabel} (y/n): ")
# # if jawaban == 'y':
# #     real.execute(f"DROP TABLE {nama_tabel}")
# #     print("Database berhasil di hapus")
# # else:
# #     print("Database ga jadi di hapus")
