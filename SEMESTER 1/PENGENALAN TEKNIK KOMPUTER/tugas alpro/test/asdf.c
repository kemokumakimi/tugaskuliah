#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

int x, y, fx, fy, n = 1, len = 1, score = 0;
char ch, dir = RIGHT;
int tailX[MAX], tailY[MAX];

void delay(int milliseconds) {
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds) {}
}

void setup() {
    x = 10;
    y = 10;
    srand(time(NULL));
    fx = rand() % 20;
    fy = rand() % 20;
}

void draw() {
    system("cls");
    printf("Score: %d\n", score);
    for(int i = 0; i < 22; i++) {
        for(int j = 0; j < 22; j++) {
            if(i == 0 || i == 21 || j == 0 || j == 21) {
                printf("#");
            } else if(i == y && j == x) {
                printf("O");
            } else if(i == fy && j == fx) {
                printf("F");
            } else {
                int flag = 0;
                for(int k = 0; k < len; k++) {
                    if(i == tailY[k] && j == tailX[k]) {
                        printf("o");
                        flag = 1;
                        break;
                    }
                }
                if(!flag) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void input() {
    if(_kbhit()) {
        ch = _getch();
        switch(ch) {
            case UP:
                if(dir != DOWN) {
                    dir = UP;
                }
                break;
            case DOWN:
                if(dir != UP) {
                    dir = DOWN;
                }
                break;
            case LEFT:
                if(dir != RIGHT) {
                    dir = LEFT;
                }
                break;
            case RIGHT:
                if(dir != LEFT) {
                    dir = RIGHT;
                }
                break;
        }
    }
}

void move() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    delay(100);
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i < len; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
    }
    if(x < 1 || x > 20 || y < 1 || y > 20) {
        printf("Game Over! You hit the wall.\n");
        printf("Press R to play again or any other key to exit.");
        ch = _getch();
    if(ch == 'r' || ch == 'R') {
            score = 0;
            len = 1;
            dir = RIGHT;
            setup();
     if(x < 1 || x > 20 || y < 1 || y > 20) {
        exit(0);
    }
    for(int i = 0; i < len; i++) {
        if(x == tailX[i] && y == tailY[i]) {
            exit(0);
        }
    }
    if(x == fx && y == fy) {
        len++;
        score += 10;
        fx = rand() % 20;
        fy = rand() % 20;
    }
}
    
int main() {
    setup();
    while(1) {
        draw();
        input();
        move();
    }
    return 0;
}