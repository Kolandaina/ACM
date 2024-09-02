import pygame
import random

# 初始化 Pygame
pygame.init()

# 定义游戏窗口大小、帧率、背景颜色
WINDOW_WIDTH = 640
WINDOW_HEIGHT = 480
FPS = 10
BACKGROUND_COLOR = (0, 0, 0)

# 定义颜色 (R,G,B)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

# 加载蛇头和身体图片
snake_head = pygame.image.load('snake_head.jpg')
snake_body = pygame.image.load('snake_body.jpg')

# 定义蛇初识位置和移动速度
snake_x = 100
snake_y = 100
snake_speed = 20

# 定义食物初始位置
food_x = random.randrange(0, WINDOW_WIDTH, snake_speed)
food_y = random.randrange(0, WINDOW_HEIGHT, snake_speed)

# 定义存储蛇身体位置的列表
snake = [(snake_x, snake_y)]

# 定义初始蛇的长度
snake_length = 1

# 定义初始分数和字体
score = 0
font = pygame.font.SysFont(None, 36)

# 创建游戏窗口
screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
pygame.display.set_caption('Snake Game')

# 循环运行游戏
clock = pygame.time.Clock()
running = True
while running:
    # 控制游戏帧率
    clock.tick(FPS)

    # 处理游戏事件
    for event in pygame.event.get():
        # 监听按键事件
        if event.type == pygame.KEYDOWN:
            # 更新蛇的位置
            if event.key == pygame.K_LEFT:
                snake_x -= snake_speed
            elif event.key == pygame.K_RIGHT:
                snake_x += snake_speed
            elif event.key == pygame.K_UP:
                snake_y -= snake_speed
            elif event.key == pygame.K_DOWN:
                snake_y += snake_speed

    # 判断蛇是否吃到食物
    if snake_x == food_x and snake_y == food_y:
        # 更新分数、食物位置和蛇的长度
        score += 1
        food_x = random.randrange(0, WINDOW_WIDTH, snake_speed)
        food_y = random.randrange(0, WINDOW_HEIGHT, snake_speed)
        snake_length += 1

    # 更新蛇和食物的位置
    snake.insert(0, (snake_x, snake_y))
    if len(snake) > snake_length:
        del snake[-1]

    # 检查是否撞墙或自撞
    if snake_x < 0 or snake_x >= WINDOW_WIDTH or snake_y < 0 or snake_y >= WINDOW_HEIGHT:
        running = False
    if (snake_x, snake_y) in snake[:-1]:
        running = False

    # 绘制游戏界面
    screen.fill(BLACK)
    # 绘制蛇、食物和分数
    for i, (x, y) in enumerate(snake):
        if i == 0:
            screen.blit(snake_head, (x, y))
        else:
            screen.blit(snake_body, (x, y))
    pygame.draw.rect(screen, GREEN, (food_x, food_y, snake_speed, snake_speed))
    score_text = font.render(f'Score: {score}', True, WHITE)
    screen.blit(score_text, (10, 10))
    pygame.display.update()

# 绘制结束界面和最终分数
screen.fill(BLACK)
gameover_text = font.render('Game Over', True, RED)
score_text = font.render(f'Total Score: {score}', True, WHITE)
screen.blit(gameover_text,
            ((WINDOW_WIDTH - gameover_text.get_width()) // 2, (WINDOW_HEIGHT - gameover_text.get_height()) // 2 - 20))
screen.blit(score_text,
            ((WINDOW_WIDTH - score_text.get_width()) // 2, (WINDOW_HEIGHT - score_text.get_height()) // 2 + 20))
pygame.display.update()

# 向操作系统发送关闭窗口消息
pygame.event.post(pygame.event.Event(pygame.QUIT))

# 等待退出
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
