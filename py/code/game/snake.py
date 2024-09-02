import random
import sys
import time
from collections import deque

import pygame
from pygame.locals import *

# 屏幕宽度和高度
Screen_Height = 480
Screen_Width = 600

# 方格大小和线条宽度
Size = 20
Line_Width = 1

# 游戏区域范围
Area_x = (0, Screen_Width // Size - 1)
Area_y = (2, Screen_Height // Size - 1)

# 食物样式列表，包括得分和颜色
Food_Style_List = [(10, (255, 100, 100)),
                   (20, (100, 255, 100)), (30, (100, 100, 255))]

# 颜色定义
Light = (100, 100, 100)
Dark = (200, 200, 200)
Black = (0, 0, 0)
Red = (200, 30, 30)
Back_Ground = (40, 40, 60)

# 绘制文本函数


def Print_Txt(screen, font, x, y, text, fcolor=(255, 255, 255)):
    Text = font.render(text, True, fcolor)
    screen.blit(Text, (x, y))

# 初始化蛇的位置


def init_snake():
    snake = deque()
    snake.append((2, Area_y[0]))
    snake.append((1, Area_y[0]))
    snake.append((0, Area_y[0]))
    return snake

# 创建食物


def Creat_Food(snake):
    food_x = random.randint(Area_x[0], Area_x[1])
    food_y = random.randint(Area_y[0], Area_y[1])
    while (food_x, food_y) in snake:
        food_x = random.randint(Area_x[0], Area_x[1])
        food_y = random.randint(Area_y[0], Area_y[1])
    return food_x, food_y

# 随机选择食物样式


def Food_Style():
    return Food_Style_List[random.randint(0, 2)]

# 游戏主函数


def main():
    pygame.init()  # 初始化Pygame
    screen = pygame.display.set_mode((Screen_Width, Screen_Height))  # 创建游戏窗口
    pygame.display.set_caption('贪吃蛇')  # 设置窗口标题
    font1 = pygame.font.SysFont('SimHei', 24)  # 设置字体
    font2 = pygame.font.SysFont(None, 72)
    fwidth, fheight = font2.size('GAME OVER')  # 计算"GAME OVER"文本的宽度和高度
    b = True
    snake = init_snake()  # 初始化蛇的起始位置
    food = Creat_Food(snake)  # 创建第一个食物
    food_style = Food_Style()  # 随机选择食物样式
    pos = (1, 0)  # 蛇的初始移动方向（向右）
    game_over = True  # 游戏是否结束
    game_start = False  # 游戏是否开始
    score = 0  # 得分
    orispeed = 0.1  # 初始速度
    speed = orispeed  # 当前速度
    last_move_time = None  # 记录上一次移动的时间
    pause = False  # 游戏是否暂停

    while True:  # 游戏主循环
        for event in pygame.event.get():  # 处理事件
            if event.type == QUIT:
                sys.exit()  # 如果点击关闭按钮，则退出游戏
            elif event.type == KEYDOWN:
                if event.key == K_RETURN:
                    if game_over:
                        game_start = True  # 如果游戏结束，按下回车键开始新游戏
                        game_over = False
                        b = True
                        snake = init_snake()  # 重新初始化蛇的位置
                        food = Creat_Food(snake)  # 创建新的食物
                        food_style = Food_Style()  # 随机选择新的食物样式
                        pos = (1, 0)  # 重置蛇的移动方向为向右
                        score = 0  # 重置得分
                        last_move_time = time.time()  # 记录当前时间作为上一次移动时间
                elif event.key == K_SPACE:
                    if not game_over:
                        pause = not pause  # 按下空格键可以暂停或恢复游戏
                elif event.key in (K_UP, K_w):
                    if b and not pos[1]:  # 如果蛇未在向下移动，可以改变移动方向为向上
                        pos = (0, -1)
                        b = False
                elif event.key in (K_DOWN, K_s):
                    if b and not pos[1]:  # 如果蛇未在向上移动，可以改变移动方向为向下
                        pos = (0, 1)
                        b = False
                elif event.key in (K_LEFT, K_a):
                    if b and not pos[0]:  # 如果蛇未在向右移动，可以改变移动方向为向左
                        pos = (-1, 0)
                        b = False
                elif event.key in (K_RIGHT, K_d):
                    if b and not pos[0]:  # 如果蛇未在向左移动，可以改变移动方向为向右
                        pos = (1, 0)
                        b = False

        screen.fill(Back_Ground)  # 清空屏幕并填充背景色

        # 绘制游戏网格
        for x in range(Size, Screen_Width, Size):
            pygame.draw.line(
                screen, Black, (x, Area_y[0] * Size), (x, Screen_Height), Line_Width)
        for y in range(Area_y[0] * Size, Screen_Height, Size):
            pygame.draw.line(screen, Black, (0, y),
                             (Screen_Width, y), Line_Width)

        if not game_over:  # 如果游戏未结束
            curTime = time.time()
            if curTime - last_move_time > speed:
                if not pause:
                    b = True
                    last_move_time = curTime
                    next_s = (snake[0][0] + pos[0], snake[0][1] + pos[1])
                    if next_s == food:  # 如果蛇头碰到食物
                        snake.appendleft(next_s)  # 蛇变长
                        score += food_style[0]  # 增加得分
                        speed = orispeed - 0.03 * (score // 100)  # 根据得分提高速度
                        food = Creat_Food(snake)  # 创建新的食物
                        food_style = Food_Style()  # 随机选择新的食物样式
                    else:
                        if Area_x[0] <= next_s[0] <= Area_x[1] and Area_y[0] <= next_s[1] <= Area_y[1] and next_s not in snake:
                            snake.appendleft(next_s)  # 蛇继续移动
                            snake.pop()
                        else:
                            game_over = True  # 游戏结束，蛇碰到墙壁或自己

        if not game_over:
            pygame.draw.rect(
                screen, food_style[1], (food[0] * Size, food[1] * Size, Size, Size), 0)  # 绘制食物

        for s in snake:
            pygame.draw.rect(screen, Dark, (s[0] * Size + Line_Width, s[1] * Size + Line_Width,
                                            Size - Line_Width * 2, Size - Line_Width * 2), 0)  # 绘制蛇的身体

        Print_Txt(screen, font1, 30, 7, f'速度: {score // 100}')  # 显示速度
        Print_Txt(screen, font1, 450, 7, f'得分: {score}')  # 显示得分

        if game_over:
            if game_start:
                Print_Txt(screen, font2, (Screen_Width - fwidth) // 2,
                          (Screen_Height - fheight) // 2, 'GAME OVER', Red)  # 显示游戏结束文字

        pygame.display.update()  # 更新游戏窗口


if __name__ == '__main__':
    main()  # 启动游戏主函数
