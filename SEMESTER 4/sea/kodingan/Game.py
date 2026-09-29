import time
from DBConn import *
from Game import *
from Snake import *


class Game:
    def __init__(self):
        curses.initscr()
        self.win = curses.newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0)
        self.win.keypad(True)
        curses.noecho()
        curses.curs_set(0)
        self.win.border(0)
        self.win.nodelay(True)
        self.key = curses.KEY_RIGHT

    def getKey(self):
        prev_key = self.key
        event = self.win.getch()
        if (event == curses.KEY_LEFT and prev_key == curses.KEY_RIGHT) or \
            (event == curses.KEY_RIGHT and prev_key == curses.KEY_LEFT) or \
            (event == curses.KEY_UP and prev_key == curses.KEY_DOWN) or \
                (event == curses.KEY_DOWN and prev_key == curses.KEY_UP):
            event = prev_key

        self.key = event if event != -1 else prev_key

        if self.key not in [curses.KEY_LEFT, curses.KEY_RIGHT, curses.KEY_UP, curses.KEY_DOWN, ESC]:
            self.key = prev_key

    def setPos(self, snake):
        y = snake.tails[0].y
        x = snake.tails[0].x
        if self.key == curses.KEY_DOWN:
            y += 1
        if self.key == curses.KEY_UP:
            y -= 1
        if self.key == curses.KEY_LEFT:
            x -= 1
        if self.key == curses.KEY_RIGHT:
            x += 1

        return y, x

    def start(self):
        score = 0
        snake = Snake(self.win)
        food = Food(self.win, snake)

        while self.key != ESC:
            self.win.addstr(0, 2, ' Score ' + str(score) + ' ')
            self.win.timeout(150 - (len(snake.tails)) //
            5 + len(snake.tails)//10 % 120)

            self.getKey()

            y, x = self.setPos(snake)

            snake.moveHead(y, x)

            if snake.collision():
                break

            if snake.eat(food.pos):
                score += 1
                food.spawn()
            else:
                snake.move()

            snake.draw()

        curses.endwin()
        return score

def menu():
    title = [
        " ________    ____    ___    __________    ___    ____",
        "|        |  |    \\  |   |  |   _______|  |   |  /   /",
        "|   _____|  |     \\ |   |  |  |          |   | /   /",
        "|  |        |      \\|   |  |  |_______   |   |/   /",
        "|  |_____   |       |   |  |   _______|  |       /",
        "|____    |  |   |\\      |  |  |          |       \\",
        " ____|   |  |   | \\     |  |  |_______   |   |\\   \\",
        "|        |  |   |  \\    |  |          |  |   | \\   \\",
        "|________|  |___|   \\___|  |__________|  |___|  \\___\\",
        "====================================================="
    ]
    for i in title:
        time.sleep(0.1)
        print(i)
    print(" MAIN MENU")
    print(" > 1. Play")
    print(" > 2. Highscore")
    print(" > 3. Exit")
    return int(input(" Enter number: "))