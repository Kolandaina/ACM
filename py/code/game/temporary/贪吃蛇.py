import random
import sys
import time
from collections import deque

import pygame
from pygame.locals import *

Screen_Height = 480
Screen_Width = 600
Size = 20
Line_Width = 1
Area_x = (0, Screen_Width // Size - 1)
Area_y = (2, Screen_Height // Size - 1)
Food_Style_List = [(10, (255, 100, 100)),
                   (20, (100, 255, 100)), (30, (100, 100, 255))]
Light = (100, 100, 100)
Dark = (200, 200, 200)
Black = (0, 0, 0)
Red = (200, 30, 30)
Back_Ground = (40, 40, 60)


def Print_Txt(screen, font, x, y, text, fcolor=(255, 255, 255)):
    Text = font.render(text, True, fcolor)
    screen.blit(Text, (x, y))


def init_snake():
    snake = deque()
    snake.append((2, Area_y[0]))
    snake.append((1, Area_y[0]))
    snake.append((0, Area_y[0]))
    return snake


def Creat_Food(snake):
    food_x = random.randint(Area_x[0], Area_x[1])
    food_y = random.randint(Area_y[0], Area_y[1])
    while (food_x, food_y) in snake:
        food_x = random.randint(Area_x[0], Area_x[1])
        food_y = random.randint(Area_y[[0], Area_y[1]])
    return food_x, food_y


def Food_Style():
    return Food_Style_List[random.randint(0, 2)]


def main():
    pygame.init()
    screen = pygame.display.set_mode((Screen_Width, Screen_Height))
    pygame.display.set_caption('贪吃蛇')
    font1 = pygame.font.SysFont('SimHei', 24)
    font2 = pygame.font.SysFont(None, 72)
    fwidth, fheight = font2.size('GAME OVER')
    b = True
    snake = init_snake()
    food = Creat_Food(snake)
    food_style = Food_Style()
    pos = (1, 0)
    game_over = True
    game_start = False
    score = 0
    orispeed = 0.1
    speed = orispeed
    last_move_time = None
    pause = False
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                sys.exit()
            elif event.type == KEYDOWN:
                if event.key == K_RETURN:
                    if game_over:
                        game_start = True
                        game_over = False
                        b = True
                        snake = init_snake()
                        food = Creat_Food(snake)
                        food_style = Food_Style()
                        pos = (1, 0)
                        score = 0
                        last_move_time = time.time()
                elif event.key == K_SPACE:
                    if not game_over:
                        pause = not pause
                elif event.key in (K_UP, K_w):
                    if b and not pos[1]:
                        pos = (0, -1)
                        b = False
                elif event.key in (K_DOWN, K_s):
                    if b and not pos[1]:
                        pos = (0, 1)
                        b = False
                elif event.key in (K_LEFT, K_a):
                    if b and not pos[0]:
                        pos = (-1, 0)
                        b = False
                elif event.key in (K_RIGHT, K_d):
                    if b and not pos[0]:
                        pos = (1, 0)
                        b = False
        screen.fill(Back_Ground)
        for x in range(Size, Screen_Width, Size):
            pygame.draw.line(
                screen, Black, (x, Area_y[0] * Size), (x, Screen_Height), Line_Width)
        for y in range(Area_y[0] * Size, Screen_Height, Size):
            pygame.draw.line(screen, Black, (0, y),
                             (Screen_Width, y), Line_Width)
        if not game_over:
            curTime = time.time()
            if curTime - last_move_time > speed:
                if not pause:
                    b = True
                    last_move_time = curTime
                    next_s = (snake[0][0] + pos[0], snake[0][1] + pos[1])
                    if next_s == food:
                        snake.appendleft(next_s)
                        score += food_style[0]
                        speed = orispeed - 0.03 * (score // 100)
                        food = Creat_Food(snake)
                        food_style = Food_Style()
                    else:
                        if Area_x[0] <= next_s[0] <= Area_x[1] and Area_y[0] <= next_s[1] <= Area_y[1] and next_s not in snake:
                            snake.appendleft(next_s)
                            snake.pop()
                        else:
                            game_over = True
        if not game_over:
            pygame.draw.rect(
                screen, food_style[1], (food[0] * Size, food[1] * Size, Size, Size), 0)
        for s in snake:
            pygame.draw.rect(screen, Dark, (s[0] * Size + Line_Width, s[1] * Size + Line_Width,
                                            Size - Line_Width * 2, Size - Line_Width * 2), 0)
        Print_Txt(screen, font1, 30, 7, f'速度: {score // 100}')
        Print_Txt(screen, font1, 450, 7, f'得分: {score}')
        if game_over:
            if game_start:
                Print_Txt(screen, font2, (Screen_Width - fwidth) // 2,
                          (Screen_Height - fheight) // 2, 'GAME OVER', Red)
        pygame.display.update()


if __name__ == '__main__':
    main()
