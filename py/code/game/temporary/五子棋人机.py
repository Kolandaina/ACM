import time
from enum import IntEnum
import pygame
import sys

t = time.localtime()
date = str(t.tm_year) + '-' + str(t.tm_mon) + '-' + \
    str(t.tm_mday) + ' ' + str(t.tm_hour) + ':' + str(t.tm_min)
version = '五子棋  time: ' + date
square_size = 40  # 单格的宽度（不是格数！是为了方便绘制棋盘用的变量
chess_size = square_size // 2 - 2  # 棋子大小
web_broad = 15  # 棋盘格数+1（nxn）
map_w = web_broad * square_size  # 棋盘长度
map_h = web_broad * square_size  # 棋盘高度
info_w = 60  # 按钮界面宽度
button_w = 120  # 按钮长宽
button_h = 45
screen_w = map_w  # 总窗口长宽
screen_h = map_h + info_w


class MAP_ENUM(IntEnum):  # 用数字表示当前格的情况
    be_empty = 0,  # 无人下
    player1 = 1,  # 玩家一，执白
    player2 = 2,  # 玩家二，执黑
    out_of_range = 3,  # 出界


class Map:  # 地图类
    def __init__(self, width, height):  # 构造函数
        self.width = width
        self.height = height
        self.map = [[0 for x in range(self.width)]
                    for y in range(self.height)]  # 存储棋盘的二维数组
        self.steps = []  # 记录步骤先后

    def get_init(self):  # 重置棋盘
        for y in range(self.height):
            for x in range(self.width):
                self.map[y][x] = 0
        self.steps = []

    def intoNextTurn(self, turn):  # 进入下一回合，交换下棋人
        if turn == MAP_ENUM.player1:
            return MAP_ENUM.player2
        else:
            return MAP_ENUM.player1

    def getLocate(self, x, y):  # 输入下标，返回具体位置
        map_x = x * square_size
        map_y = y * square_size
        return (map_x, map_y, square_size, square_size)  # 返回位置信息

    def getIndex(self, map_x, map_y):  # 输入具体位置，返回下标
        x = map_x // square_size
        y = map_y // square_size
        return (x, y)

    def isInside(self, map_x, map_y):  # 是否在有效范围内
        if (map_x <= 0 or map_x >= map_w or
                map_y <= 0 or map_y >= map_h):
            return False
        return True

    def isEmpty(self, x, y):  # 当前格子是否已经有棋子
        return (self.map[y][x] == 0)

    def click(self, x, y, type):  # 点击的下棋动作
        self.map[y][x] = type.value  # 下棋
        self.steps.append((x, y))  # 记录步骤信息

    def printChessPiece(self, screen):  # 绘制棋子
        player_one = (255, 245, 238)  # 象牙白
        player_two = (41, 36, 33)  # 烟灰
        player_color = [player_one, player_two]
        for i in range(len(self.steps)):
            x, y = self.steps[i]
            map_x, map_y, width, height = self.getLocate(x, y)
            pos, radius = (map_x + width // 2, map_y + height // 2), chess_size
            turn = self.map[y][x]
            pygame.draw.circle(
                screen, player_color[turn - 1], pos, radius)  # 画棋子

    def drawBoard(self, screen):  # 画棋盘
        color = (0, 0, 0)  # 线色
        for y in range(self.height):
            # 画横着的棋盘线
            start_pos, end_pos = (square_size // 2, square_size // 2 + square_size * y), (
                map_w - square_size // 2, square_size // 2 + square_size * y)
            pygame.draw.line(screen, color, start_pos, end_pos, 1)
        for x in range(self.width):
            # 画竖着的棋盘线
            start_pos, end_pos = (square_size // 2 + square_size * x, square_size // 2), (
                square_size // 2 + square_size * x, map_h - square_size // 2)
            pygame.draw.line(screen, color, start_pos, end_pos, 1)


class SITUATION(IntEnum):  # 棋型
    NONE = 0,  # 无
    SLEEP_TWO = 1,  # 眠二
    LIVE_TWO = 2,  # 活二
    SLEEP_THREE = 3,  # 眠三
    LIVE_THREE = 4,  # 活三
    CHONG_FOUR = 5,  # 冲四
    LIVE_FOUR = 6,  # 活四
    LIVE_FIVE = 7,  # 活五


SITUATION_NUM = 8
FIVE = SITUATION.LIVE_FIVE.value
L4, L3, L2 = SITUATION.LIVE_FOUR.value, SITUATION.LIVE_THREE.value, SITUATION.LIVE_TWO.value
S4, S3, S2 = SITUATION.CHONG_FOUR.value, SITUATION.SLEEP_THREE.value, SITUATION.SLEEP_TWO.value


class MyChessAI():
    def __init__(self, chess_len):  # 构造函数
        self.len = chess_len
        self.record = [[[0, 0, 0, 0]
                        for i in range(chess_len)] for j in range(chess_len)]
        self.count = [[0 for i in range(SITUATION_NUM)] for j in range(2)]
        self.position_isgreat = [
            [(web_broad - max(abs(i - web_broad / 2 + 1), abs(j - web_broad / 2 + 1)))
             for i in range(chess_len)]
            for j in range(chess_len)]

    def get_init(self):
        for i in range(self.len):
            for j in range(self.len):
                for k in range(4):
                    self.record[i][j][k] = 0
        for i in range(len(self.count)):
            for j in range(len(self.count[0])):
                self.count[i][j] = 0
        self.save_count = 0

    def isWin(self, board, turn):
        return self.evaluate(board, turn, True)

    def genmove(self, board, turn):
        moves = []
        for y in range(self.len):
            for x in range(self.len):
                if board[y][x] == 0:
                    score = self.position_isgreat[y][x]
                    moves.append((score, x, y))
        moves.sort(reverse=True)
        return moves

    def search(self, board, turn):
        moves = self.genmove(board, turn)
        bestmove = None
        max_score = -99999
        for score, x, y in moves:
            board[y][x] = turn.value
            score = self.evaluate(board, turn)
            board[y][x] = 0
            if score > max_score:
                max_score = score
                bestmove = (max_score, x, y)
        return bestmove

    def findBestChess(self, board, turn):
        score, x, y = self.search(board, turn)
        return (x, y)

    def getScore(self, mychess, yourchess):
        mscore, oscore = 0, 0
        if mychess[FIVE] > 0:
            return (10000, 0)
        if yourchess[FIVE] > 0:
            return (0, 10000)
        if mychess[S4] >= 2:
            mychess[L4] += 1
        if yourchess[L4] > 0:
            return (0, 9050)
        if yourchess[S4] > 0:
            return (0, 9040)
        if mychess[L4] > 0:
            return (9030, 0)
        if mychess[S4] > 0 and mychess[L3] > 0:
            return (9020, 0)
        if yourchess[L3] > 0 and mychess[S4] == 0:
            return (0, 9010)
        if (mychess[L3] > 1 and yourchess[L3] == 0 and yourchess[S3] == 0):
            return (9000, 0)
        if mychess[S4] > 0:
            mscore += 2000
        if mychess[L3] > 1:
            mscore += 500
        elif mychess[L3] > 0:
            mscore += 100
        if yourchess[L3] > 1:
            oscore += 2000
        elif yourchess[L3] > 0:
            oscore += 400
        if mychess[S3] > 0:
            mscore += mychess[S3] * 10
        if yourchess[S3] > 0:
            oscore += yourchess[S3] * 10
        if mychess[L2] > 0:
            mscore += mychess[L2] * 4
        if yourchess[L2] > 0:
            oscore += yourchess[L2] * 4
        if mychess[S2] > 0:
            mscore += mychess[S2] * 4
        if yourchess[S2] > 0:
            oscore += yourchess[S2] * 4
        return (mscore, oscore)

    def evaluate(self, board, turn, checkWin=False):
        self.get_init()
        if turn == MAP_ENUM.player1:
            me = 1
            you = 2
        else:
            me = 2
            you = 1
        for y in range(self.len):
            for x in range(self.len):
                if board[y][x] == me:
                    self.evaluatePoint(board, x, y, me, you)
                elif board[y][x] == you:
                    self.evaluatePoint(board, x, y, you, me)
        mychess = self.count[me - 1]
        yourchess = self.count[you - 1]
        if checkWin:
            return mychess[FIVE] > 0
        else:
            mscore, oscore = self.getScore(mychess, yourchess)
            return (mscore - oscore)

    def evaluatePoint(self, board, x, y, me, you):
        direction = [(1, 0), (0, 1), (1, 1), (1, -1)]
        for i in range(4):
            if self.record[y][x][i] == 0:
                self.getBasicSituation(
                    board, x, y, i, direction[i], me, you, self.count[me - 1])
            else:
                self.save_count += 1

    def getLine(self, board, x, y, direction, me, you):
        line = [0 for i in range(9)]
        tmp_x = x + (-5 * direction[0])
        tmp_y = y + (-5 * direction[1])
        for i in range(9):
            tmp_x += direction[0]
            tmp_y += direction[1]
            if (tmp_x < 0 or tmp_x >= self.len or tmp_y < 0 or tmp_y >= self.len):
                line[i] = you  # 出界
            else:
                line[i] = board[tmp_y][tmp_x]
        return line

    def getBasicSituation(self, board, x, y, dir_index, dir, me, you, count):
        # record赋值
        def setRecord(self, x, y, left, right, dir_index, direction):
            tmp_x = x + (-5 + left) * direction[0]
            tmp_y = y + (-5 + left) * direction[1]
            for i in range(left, right):
                tmp_x += direction[0]
                tmp_y += direction[1]
                self.record[tmp_y][tmp_x][dir_index] = 1

        empty = MAP_ENUM.be_empty.value
        left_index, right_index = 4, 4
        line = self.getLine(board, x, y, dir, me, you)
        while right_index < 8:
            if line[right_index + 1] != me:
                break
            right_index += 1
        while left_index > 0:
            if line[left_index - 1] != me:
                break
            left_index -= 1
        left_range, right_range = left_index, right_index
        while right_range < 8:
            if line[right_range + 1] == you:
                break
            right_range += 1
        while left_range > 0:
            if line[left_range - 1] == you:
                break
            left_range -= 1
        chess_range = right_range - left_range + 1
        if chess_range < 5:
            setRecord(self, x, y, left_range, right_range, dir_index, dir)
            return SITUATION.NONE
        setRecord(self, x, y, left_index, right_index, dir_index, dir)
        m_range = right_index - left_index + 1
        if m_range == 5:
            count[FIVE] += 1
        if m_range == 4:
            left_empty = right_empty = False
            if line[left_index - 1] == empty:
                left_empty = True
            if line[right_index + 1] == empty:
                right_empty = True
            if left_empty and right_empty:
                count[L4] += 1
            elif left_empty or right_empty:
                count[S4] += 1
        if m_range == 3:
            left_empty = right_empty = False
            left_four = right_four = False
            if line[left_index - 1] == empty:
                if line[left_index - 2] == me:
                    setRecord(self, x, y, left_index - 2,
                              left_index - 1, dir_index, dir)
                    count[S4] += 1
                    left_four = True
                left_empty = True
            if line[right_index + 1] == empty:
                if line[right_index + 2] == me:
                    setRecord(self, x, y, right_index + 1,
                              right_index + 2, dir_index, dir)
                    count[S4] += 1
                    right_four = True
                right_empty = True
            if left_four or right_four:
                pass
            elif left_empty and right_empty:
                if chess_range > 5:
                    count[L3] += 1
                else:
                    count[S3] += 1
            elif left_empty or right_empty:
                count[S3] += 1
        if m_range == 2:
            left_empty = right_empty = False
            left_three = right_three = False
            if line[left_index - 1] == empty:
                if line[left_index - 2] == me:
                    setRecord(self, x, y, left_index - 2,
                              left_index - 1, dir_index, dir)
                    if line[left_index - 3] == empty:
                        if line[right_index + 1] == empty:
                            count[L3] += 1
                        else:
                            count[S3] += 1
                        left_three = True
                    elif line[left_index - 3] == you:
                        if line[right_index + 1] == empty:
                            count[S3] += 1
                            left_three = True
                left_empty = True
            if line[right_index + 1] == empty:
                if line[right_index + 2] == me:
                    if line[right_index + 3] == me:
                        setRecord(self, x, y, right_index + 1,
                                  right_index + 2, dir_index, dir)
                        count[S4] += 1
                        right_three = True
                    elif line[right_index + 3] == empty:
                        if left_empty:
                            count[L3] += 1
                        else:
                            count[S3] += 1
                        right_three = True
                    elif left_empty:
                        count[S3] += 1
                        right_three = True
                right_empty = True
            if left_three or right_three:
                pass
            elif left_empty and right_empty:
                count[L2] += 1
            elif left_empty or right_empty:
                count[S2] += 1
        if m_range == 1:
            left_empty = right_empty = False
            if line[left_index - 1] == empty:
                if line[left_index - 2] == me:
                    if line[left_index - 3] == empty:
                        if line[right_index + 1] == you:
                            count[S2] += 1
                left_empty = True
            if line[right_index + 1] == empty:
                if line[right_index + 2] == me:
                    if line[right_index + 3] == empty:
                        if left_empty:
                            count[L2] += 1
                        else:
                            count[S2] += 1
                elif line[right_index + 2] == empty:
                    if line[right_index + 3] == me and line[right_index + 4] == empty:
                        count[L2] += 1
        return SITUATION.NONE


class Button:
    def __init__(self, screen, text, x, y, color, enable):
        self.screen = screen
        self.width = button_w
        self.height = button_h
        self.button_color = color
        self.text_color = (255, 255, 255)
        self.enable = enable
        self.font = pygame.font.SysFont(None, button_h * 2 // 3)
        self.rect = pygame.Rect(0, 0, self.width, self.height)
        self.rect.topleft = (x, y)
        self.text = text
        self.init_msg()

    def init_msg(self):
        if self.enable:
            self.msg_image = self.font.render(
                self.text, True, self.text_color, self.button_color[0])
        else:
            self.msg_image = self.font.render(
                self.text, True, self.text_color, self.button_color[1])
        self.msg_image_rect = self.msg_image.get_rect()
        self.msg_image_rect.center = self.rect.center

    def draw(self):
        if self.enable:
            self.screen.fill(self.button_color[0], self.rect)
        else:
            self.screen.fill(self.button_color[1], self.rect)
        self.screen.blit(self.msg_image, self.msg_image_rect)


class WhiteStartButton(Button):
    def __init__(self, screen, text, x, y):
        super().__init__(screen, text, x, y, [
            (26, 173, 25), (158, 217, 157)], True)

    def click(self, game):
        if self.enable:
            game.start()
            game.winner = None
            game.multiple = False
            self.msg_image = self.font.render(
                self.text, True, self.text_color, self.button_color[1])
            self.enable = False
            return True
        return False

    def unclick(self):
        if not self.enable:
            self.msg_image = self.font.render(
                self.text, True, self.text_color, self.button_color[0])
            self.enable = True


class BlackStartButton(Button):
    def __init__(self, screen, text, x, y):
        super().__init__(screen, text, x, y, [
            (26, 173, 25), (158, 217, 157)], True)

    def click(self, game):
        if self.enable:
            game.start()
            game.winner = None
            game.multiple = False
            game.useAI = True
            self.msg_image = self.font.render(
                self.text, True, self.text_color, self.button_color[1])
            self.enable = False
            return True
        return False

    def unclick(self):
        if not self.enable:
            self.msg_image = self.font.render(
                self.text, True, self.text_color, self.button_color[0])
            self.enable = True


class GiveupButton(Button):
    def __init__(self, screen, text, x, y):
        super().__init__(screen, text, x, y, [
            (230, 67, 64), (236, 139, 137)], False)

    def click(self, game):
        if self.enable:
            game.is_play = False
            if game.winner is None:
                game.winner = game.map.intoNextTurn(game.player)
            self.msg_image = self.font.render(
                self.text, True, self.text_color, self.button_color[1])
            self.enable = False
            return True
        return False

    def unclick(self):
        if not self.enable:
            self.msg_image = self.font.render(
                self.text, True, self.text_color, self.button_color[0])
            self.enable = True


class MultiStartButton(Button):
    def __init__(self, screen, text, x, y):
        super().__init__(screen, text, x, y, [
            (153, 51, 250), (221, 160, 221)], True)

    def click(self, game):
        if self.enable:
            game.start()
            game.winner = None
            game.multiple = True
            self.msg_image = self.font.render(
                self.text, True, self.text_color, self.button_color[1])
            self.enable = False
            return True
        return False

    def unclick(self):
        if not self.enable:
            self.msg_image = self.font.render(
                self.text, True, self.text_color, self.button_color[0])
            self.enable = True


class Game:
    def __init__(self, caption):
        pygame.init()
        self.screen = pygame.display.set_mode([screen_w, screen_h])
        pygame.display.set_caption(caption)
        self.clock = pygame.time.Clock()
        self.buttons = []
        self.buttons.append(WhiteStartButton(
            self.screen, 'Pick White', 10, map_h))
        self.buttons.append(BlackStartButton(
            self.screen, 'Pick Black', 170, map_h))
        self.buttons.append(GiveupButton(self.screen, 'Surrender', 330, map_h))
        self.buttons.append(MultiStartButton(
            self.screen, 'Multiple', 490, map_h))
        self.is_play = False
        self.map = Map(web_broad, web_broad)
        self.player = MAP_ENUM.player1
        self.action = None
        self.AI = MyChessAI(web_broad)
        self.useAI = False
        self.winner = None
        self.multiple = False

    def start(self):
        self.is_play = True
        self.player = MAP_ENUM.player1
        self.map.get_init()

    def play(self):
        self.clock.tick(60)
        wood_color = (210, 180, 140)
        pygame.draw.rect(self.screen, wood_color,
                         pygame.Rect(0, 0, map_w, screen_h))
        pygame.draw.rect(self.screen, (255, 255, 255),
                         pygame.Rect(map_w, 0, info_w, screen_h))
        for button in self.buttons:
            button.draw()
        if self.is_play and not self.isOver():
            if self.useAI and not self.multiple:
                x, y = self.AI.findBestChess(self.map.map, self.player)
                self.checkClick(x, y, True)
                self.useAI = False
            if self.action is not None:
                self.checkClick(self.action[0], self.action[1])
                self.action = None
            if not self.isOver():
                self.changeMouseShow()
        if self.isOver():
            self.showWinner()
        self.map.drawBoard(self.screen)
        self.map.printChessPiece(self.screen)

    def changeMouseShow(self):
        map_x, map_y = pygame.mouse.get_pos()
        x, y = self.map.getIndex(map_x, map_y)
        if self.map.isInside(map_x, map_y) and self.map.isEmpty(x, y):
            pygame.mouse.set_visible(False)
            smoke_blue = (176, 224, 230)
            pos, radius = (map_x, map_y), chess_size
            pygame.draw.circle(self.screen, smoke_blue, pos, radius)
        else:
            pygame.mouse.set_visible(True)

    def checkClick(self, x, y, isAI=False):
        self.map.click(x, y, self.player)
        if self.AI.isWin(self.map.map, self.player):
            self.winner = self.player
            self.click_button(self.buttons[2])
        else:
            self.player = self.map.intoNextTurn(self.player)
            if not isAI:
                self.useAI = True

    def mouseClick(self, map_x, map_y):
        if self.is_play and self.map.isInside(map_x, map_y) and not self.isOver():
            x, y = self.map.getIndex(map_x, map_y)
            if self.map.isEmpty(x, y):
                self.action = (x, y)

    def isOver(self):
        return self.winner is not None

    def showWinner(self):
        def showFont(screen, text, location_x, locaiton_y, height):
            font = pygame.font.SysFont(None, height)
            font_image = font.render(
                text, True, (255, 215, 0), (255, 255, 255))
            font_image_rect = font_image.get_rect()
            font_image_rect.x = location_x
            font_image_rect.y = locaiton_y
            screen.blit(font_image, font_image_rect)

        if self.winner == MAP_ENUM.player1:
            str = 'White Wins!'
        else:
            str = 'Black Wins!'
        showFont(self.screen, str, map_w / 5, screen_h / 8, 100)
        pygame.mouse.set_visible(True)

    def click_button(self, button):
        if button.click(self):
            for tmp in self.buttons:
                if tmp != button:
                    tmp.unclick()

    def check_buttons(self, mouse_x, mouse_y):
        for button in self.buttons:
            if button.rect.collidepoint(mouse_x, mouse_y):
                self.click_button(button)
                break


if __name__ == '__main__':
    game = Game(version)
    while True:
        game.play()
        pygame.display.update()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.MOUSEBUTTONDOWN:
                mouse_x, mouse_y = pygame.mouse.get_pos()
                game.mouseClick(mouse_x, mouse_y)
                game.check_buttons(mouse_x, mouse_y)
