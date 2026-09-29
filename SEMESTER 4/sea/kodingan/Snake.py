import curses
from random import randint

WINDOW_WIDTH = 60
WINDOW_HEIGHT = 20
ESC = 27


class Tail:
    char = '*'

    def __init__(self, y, x):
        self.setTail(y, x)

    def setTail(self, y, x):
        self.y = y
        self.x = x
        self.pos = (y, x)


class Snake():
    head = ()

    def __init__(self, win):
        self.tails = []
        self.win = win
        self.addEntry(4, 2)
        self.addEntry(4, 3)
        self.addEntry(4, 4)

    def collision(self):
        tail = []
        y = self.tails[0].y
        x = self.tails[0].x
        for tails in self.tails:
            tail.append(tails.pos)

        if y == 0 or y == WINDOW_HEIGHT - 1 or \
            x == 0 or x == WINDOW_WIDTH - 1 or \
            self.head in tail[1:]:
            curses.flash()
            curses.beep()
            return True
        else:
            return False

    def eat(self, food):
        return self.head == food

    def move(self):
        last = self.tails.pop()
        self.win.addch(last.y, last.x, ' ')

    def draw(self):
        self.win.addch(self.tails[0].y, self.tails[0].x, '*')

    def moveHead(self, y, x):
        self.addEntry(y, x)

    def addEntry(self, y, x):
        self.head = (y, x)
        self.tails.insert(0, Tail(y, x))


class Food():
    def __init__(self, win, snake):
        self.snake = snake
        self.win = win
        self.setPos(6, 6)
        win.addch(self.y, self.x, '#')

    def setPos(self, y, x):
        self.y = y
        self.x = x
        self.pos = (y, x)

    def spawn(self):
        curses.flash()
        self.pos = ()
        while self.pos == ():
            self.setPos(randint(1, WINDOW_HEIGHT-2),
                        randint(1, WINDOW_WIDTH - 2))
            for tail in self.snake.tails:
                if self.pos == tail.pos:
                    self.pos = ()
        self.win.addch(self.y, self.x, '#')