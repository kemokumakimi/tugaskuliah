import mysql.connector

class Score:
    def __init__(self):
            self.__mydb = mysql.connector.connect(
                host="localhost",
                user="root",
                password="",
                database="snake"
            )
            self.__mycursor = self.__mydb.cursor()
        
    def getAllData(self):
            self.__mycursor.execute("SELECT name, value FROM score ORDER BY value DESC LIMIT 10")
            return self.__mycursor.fetchall()
        

    def insert(self, name, score):
            sql = "INSERT INTO score (name, value) VALUES (%s, %s)"
            val = (name, score)
            self.__mycursor.execute(sql, val)
            self.__mydb.commit()

