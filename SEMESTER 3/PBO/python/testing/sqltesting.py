import mysql.connector

db = mysql.connector.connect (
    host = "localhost",
    user = "root",
    password = "",
    database = "seantuy"
)
real = db.cursor()
table_content = '''CREATE TABLE nama_mhs (
    no_teman INT AUTO_INCREMENT PRIMARY KEY,
    nama VARCHAR(255),
    nim VARCHAR(255)
)
'''
real.execute(table_content)
print("Table Created")