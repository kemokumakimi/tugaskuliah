
from turtle import *
import turtle as tur
from random import randint
tur.colormode(255)

def daisy():

    tur.bgcolor((0,0,0))    
    for i in range(2):

        tur.begin_fill()
        if i == 0:
            tur.fillcolor((252,255,255))
            tur.pencolor((252, 255, 255))
            tur.speed(20)
            tur.pensize(1)
        else:
            tur.fillcolor((248, 220, 0))
            tur.pencolor((248, 220, 0))
            tur.speed(0)
            tur.pensize(5)
        for j in range(12):

            circle(500-(i*300), 30)
            left(90)
            circle(60, 90)
            left(120)
            circle(60, 90)
            left(90)
            circle(60, 90)
            left(120)
            circle(60, 90)
            left(90)
            circle(500-(i*300),  30 )
        tur.end_fill()

daisy()
mainloop()