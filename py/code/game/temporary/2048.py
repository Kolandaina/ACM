import itertools
import math
import random
import sys

__mataclass__ = type


class map2048():
    def reset(self):
        self.__row = 4
        self.__col = 4
        self.data = [
            [0 for x in range(self.__col)]
            for y in range(self.__row)
        ]
        self.fill2()
        self.fill2()

    def __init__(self):
        self.reset()

    def get_space_count(self):
        return sum(r.count(0) for r in self.data)

    def get_score(self):
        s = 0
        for r in self.data:
            for c in r:
                s += 0 if c < 4 else c * int((math.log(c, 2) - 1.0))
        return s

    def fill2(self):
        blank_count = self.get_space_count()
        if blank_count == 0:
            return False
        pos = random.randrange(0, blank_count)
        offset = 0
        for r in self.data:
            for ci in range(self.__col):
                if r[ci] == 0:
                    if offset == pos:
                        r[ci] = 2
                        return True
                    offset += 1

    def is_gameover(self):
        for r in self.data:
            if r.count(0):
                return False
            for i in range(self.__col - 1):
                if r[i] == r[i + 1]:
                    return False
        return all(
            self.data[r][c] != self.data[r + 1][c]
            for c, r in itertools.product(
                range(self.__col - 1), range(self.__row - 1)
            )
        )

    def left(self):
        moveflag = False
        for times in range(self.__col - 1):
            for r in self.data:
                for c in range(self.__col - 1):
                    if r[c] == 0:
                        moveflag = True
                        r[c] = r[c + 1]
                        r[c + 1] = 0
        for r in self.data:
            for c in range(self.__col - 1):
                if r[c] == r[c + 1]:
                    moveflag = True
                    r[c] *= 2
                    r[c + 1] = 0
        for times in range(self.__col - 1):
            for r in self.data:
                for c in range(self.__col - 1):
                    if r[c] == 0:
                        moveflag = True
                        r[c] = r[c + 1]
                        r[c + 1] = 0
        return moveflag

    def right(self):
        for r in self.data:
            r.reverse()
        moveflag = self.left()
        for r in self.data:
            r.reverse()
        return moveflag

    def up(self):
        moveflag = False
        for times, c in itertools.product(range(self.__row - 1), range(self.__col)):
            for r in range(self.__row - 1):
                if self.data[r][c] == 0:
                    moveflag = True
                    self.data[r][c] = self.data[r + 1][c]
                    self.data[r + 1][c] = 0
        for c, r in itertools.product(range(self.__col), range(self.__row - 1)):
            if self.data[r][c] == self.data[r + 1][c]:
                moveflag = True
                self.data[r][c] *= 2
                self.data[r + 1][c] = 0
        for times, c in itertools.product(range(self.__row - 1), range(self.__col)):
            for r in range(self.__row - 1):
                if self.data[r][c] == 0:
                    moveflag = True
                    self.data[r][c] = self.data[r + 1][c]
                    self.data[r + 1][c] = 0
        return moveflag

    def down(self):
        self.data.reverse()
        moveflag = self.up()
        self.data.reverse()
        return moveflag


if (sys.version_info > (3, 0)):
    from tkinter import *
    from tkinter import messagebox
game = map2048()
keymap = {
    'a': game.left,
    'd': game.right,
    'w': game.up,
    's': game.down,
    'Left': game.left,
    'Right': game.right,
    'Up': game.up,
    'Down': game.down,
    'q': exit,
}
game_bg_color = "#bbada0"
mapcolor = {
    0: ("#bbada0", "#0E050A"),
    2: ("#DAF5FF", "#0E050A"),
    4: ("#A5E2FF", "#0E050A"),
    8: ("#5ABBFF", "#0E050A"),
    16: ("#1F39FF", "#0E050A"),
    32: ("#0012C6", "#0E050A"),
    64: ("#3B0080", "#0E050A"),
    128: ("#570075", "#0E050A"),
    256: ("#40004A", "#0E050A"),
    512: ("#750046", "#0E050A"),
    1024: ("#690039", "#0E050A"),
    2048: ("#5A0000", "#0E050A"),
    4096: ("#004000", "#0E050A"),
    8192: ("#008000", "#0E050A"),
}
map_labels = []


def on_mouse_down(event):
    print("clicked at", event.x, event.y)


def on_key_down(event):
    keysym = event.keysym
    if keysym in keymap and keymap[keysym]():
        game.fill2()
    update_ui()
    if game.is_gameover():
        if mb := messagebox.askyesno(
            title="gameover", message="游戏结束!\n是否退出游戏!"
        ):
            exit()
        else:
            game.reset()
            update_ui()


def update_ui():
    for r, c in itertools.product(range(len(game.data)), range(len(game.data[0]))):
        number = game.data[r][c]
        label = map_labels[r][c]
        label['text'] = str(number) if number else ''
        label['bg'] = mapcolor[number][0]
        label['foreground'] = mapcolor[number][1]
    label_score['text'] = str(game.get_score())


root = Tk()
root.title('2048')
frame = Frame(root, width=300, height=300, bg=game_bg_color)
frame.grid(sticky=N + E + W + S)
frame.focus_set()
frame.bind("<Key>", on_key_down)
frame.bind("<ButtonRelease-1>", on_mouse_down)
for r in range(len(game.data)):
    row = []
    for c in range(len(game.data[0])):
        value = game.data[r][c]
        text = '' if value == 0 else str(value)
        label = Label(frame, text=text, width=4, height=2,
                      font=("黑体", 30, "bold"))
        label.grid(row=r, column=c, padx=5, pady=5, sticky=N + E + W + S)
        row.append(label)
    map_labels.append(row)
bottom_row = len(game.data)
print("button", bottom_row)
label = Label(frame, text='分数', font=("楷体", 30, "bold"),
              bg="#bbada0", fg="#eee4da")
label.grid(row=bottom_row, column=0, padx=5, pady=5)
label_score = Label(frame, text='0', font=("楷体", 30, "bold"),
                    bg="#bbada0", fg="#ffffff")
label_score.grid(row=bottom_row, columnspan=2, column=1, padx=5, pady=5)


def reset_game():
    game.reset()
    update_ui()


restart_button = Button(frame, text='重来', font=("楷体", 20, "bold"),
                        bg="#8f7a66", fg="#f9f6f2", command=reset_game)
restart_button.grid(row=bottom_row, column=3, padx=5, pady=5)
update_ui()
root.mainloop()
