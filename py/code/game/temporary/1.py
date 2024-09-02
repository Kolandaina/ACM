#!D://Anaconda//envs//pytorch python
# -*- coding: UTF-8 -*-
'''
@Desc: 
@File: 1_SetStages.py
@Author: wenrj
@Date: 2023/07/03 10:53:55
'''
import pygame
import constants as C
import os, random

pygame.init()
pygame.display.set_mode(C.SCREEN_SIZE)
pygame.display.set_caption("小学期pygame")
SCREEN = pygame.display.get_surface()
CLOCK  = pygame.time.Clock()

# 加载图片素材
IMAGES = {}
for image in os.listdir('../assets/sprites'):
    name, extension = os.path.splitext(image)
    path = os.path.join('../assets/sprites', image)
    IMAGES[name] = pygame.image.load(path)


# 加载音频文件
AUDIOS = {}
for audio in os.listdir('../assets/audio'):
    name, extension = os.path.splitext(audio)
    path = os.path.join('../assets/audio', audio)
    AUDIOS[name] = pygame.mixer.Sound(path)


FLOOR_Y = C.SCREEN_H - IMAGES['floor'].get_height()
FLOOR_GAP = IMAGES['floor'].get_width() - C.SCREEN_W

def main():
    while True:
        IMAGES['bgpic'] = IMAGES[random.choice(['day', 'night'])]
        color = random.choice(['blue', 'red', 'yellow'])
        IMAGES['bird'] = [IMAGES[color + '-up'], 
                          IMAGES[color + '-mid'],
                          IMAGES[color + '-down']]
        pipe = IMAGES[random.choice(['red-pipe', 'green-pipe'])]
        IMAGES['pipes'] = [pipe, 
                           pygame.transform.flip(pipe, False, True)]
        menu_window()
        result = game_window()
        end_window(result)

def menu_window():
    guide_x = (C.SCREEN_W - IMAGES['guide'].get_width()) / 2
    guide_y = (FLOOR_Y - IMAGES['guide'].get_height()) / 2
    bird_x  = C.SCREEN_W * 0.2
    bird_y  = (C.SCREEN_H - IMAGES['bird'][1].get_height()) / 2
    floor_x = 0
    AUDIOS['start'].play()
    bird = Bird(bird_x, bird_y)

    while True:
        for event in pygame.event.get():
            # 游戏退出事件
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN and \
               event.key  == pygame.K_SPACE:
                return
        # 地板移动
        floor_x -= C.FLOOR_VAL
        if -floor_x >= FLOOR_GAP:
            floor_x = 0

        bird.upAndDown()

        SCREEN.blit(IMAGES['bgpic'], (0, 0)) # 背景
        SCREEN.blit(IMAGES['floor'], (floor_x, FLOOR_Y)) # 地板
        SCREEN.blit(IMAGES['guide'], (guide_x, guide_y)) # 引导页面
        SCREEN.blit(bird.image, bird.rect)  # 小鸟
        pygame.display.update()
        CLOCK.tick(C.FPS)
    

def game_window():
    bird_x = (C.SCREEN_W - IMAGES['bird'][1].get_width()) / 2
    bird_y = (FLOOR_Y - IMAGES['bird'][1].get_height()) / 2
    floor_x = 0
    bird = Bird(bird_x, bird_y)
    while True:
        flap = False
        for event in pygame.event.get():
            # 游戏退出事件
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
               if event.key  == pygame.K_SPACE:
                   flap = True
                   AUDIOS['flap'].play()
        floor_x -= C.FLOOR_VAL
        if -floor_x >= FLOOR_GAP:
            floor_x = 0 

        if bird.rect.y <= 0 or bird.rect.y >= FLOOR_Y:
            AUDIOS['hit'].play()
            return {'bird': bird}

        bird.update(flap)    
        SCREEN.blit(IMAGES['bgpic'], (0, 0)) # 背景
        SCREEN.blit(IMAGES['floor'], (floor_x, FLOOR_Y)) # 地板
        SCREEN.blit(bird.image, bird.rect)  # 小鸟
        pygame.display.update()
        CLOCK.tick(C.FPS)

def end_window(result):
    gameover_x = (C.SCREEN_W - IMAGES['gameover'].get_width()) / 2
    gameover_y = (FLOOR_Y - IMAGES['gameover'].get_height()) / 2
    AUDIOS['die'].play()
    floor_x = 0
    bird = result['bird']
    while True:
        for event in pygame.event.get():
            # 游戏退出事件
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN and \
               event.key  == pygame.K_SPACE:
                return
        floor_x -= C.FLOOR_VAL
        if -floor_x >= FLOOR_GAP:
            floor_x = 0
        bird.go_die()
        SCREEN.blit(IMAGES['bgpic'], (0, 0)) # 背景
        SCREEN.blit(IMAGES['floor'], (floor_x, FLOOR_Y)) # 地板
        SCREEN.blit(bird.image, bird.rect)
        SCREEN.blit(IMAGES['gameover'], (gameover_x, gameover_y)) # 游戏结束
        pygame.display.update()
        CLOCK.tick(C.FPS)

class Bird():
    def __init__(self, x, y) -> None:
        self.idx = 0
        self.frames = [0] * 5 + [1] * 5 + [2] * 5 + [1] * 5
        self.images = IMAGES['bird']
        self.image  = self.images[self.frames[self.idx]]
        self.rect   = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y
        self.bird_y_range = [self.rect.y - 8, self.rect.y + 8]

        self.y_val = -10    # 初始初度
        self.max_y_val = 10 # 最大下落速度
        self.gravity = 1    # 重力加速度

        self.rotate = 45    # 角度
        self.max_rotate = -20 # 朝下最大角度
        self.rotate_val = -3   # 角度变化速度

        self.y_val_after_flap = -10  
        self.rotate_after_flap = 45

    def update(self, flap=False):
        if flap:
            self.y_val = self.y_val_after_flap
            self.rotate = self.rotate_after_flap

        self.idx += 1
        self.idx %= len(self.frames)
        self.image = self.images[self.frames[self.idx]]

        self.y_val = min(self.y_val + self.gravity, self.max_y_val)
        self.rect.y = self.rect.y + self.y_val

        self.rotate = max(self.rotate + self.rotate_val, self.max_rotate)
        self.image  = pygame.transform.rotate(self.image, self.rotate)

    def upAndDown(self):
        self.idx += 1
        self.idx %= len(self.frames)
        self.image = self.images[self.frames[self.idx]]
        # 小鸟上下移动
        self.rect.y += C.BIRD_Y_VAL
        if self.rect.y >= self.bird_y_range[1] or \
           self.rect.y <= self.bird_y_range[0]:
            C.BIRD_Y_VAL *= -1
    
    def go_die(self):
        if self.rect.y <= FLOOR_Y:
            self.rect.y += self.max_y_val
            self.rotate = -90
            self.image  = self.images[self.frames[self.idx]]
            self.image = pygame.transform.rotate(self.image, self.rotate)
            

if __name__ == '__main__':
    main()