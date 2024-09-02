import turtle
import datetime
import time


def draw_gap():
    turtle.penup()
    turtle.fd(5)


def draw_line(draw):
    draw_gap()
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(40)
    draw_gap()
    turtle.right(90)


def draw_digit(d):
    draw_line(True) if d in [2, 3, 4, 5, 6, 8, 9] else draw_line(False)
    draw_line(True) if d in [0, 1, 3, 4, 5, 6, 7, 8, 9] else draw_line(False)
    draw_line(True) if d in [0, 2, 3, 5, 6, 8, 9] else draw_line(False)
    draw_line(True) if d in [0, 2, 6, 8] else draw_line(False)
    turtle.left(90)
    draw_line(True) if d in [0, 4, 5, 6, 8, 9] else draw_line(False)
    draw_line(True) if d in [0, 2, 3, 5, 6, 7, 8, 9] else draw_line(False)
    draw_line(True) if d in [0, 1, 2, 3, 4, 7, 8, 9] else draw_line(False)
    turtle.left(180)
    turtle.penup()
    turtle.fd(20)


def draw_date(date):
    for i in date:
        if i == '+':
            turtle.write('年', font=("Arial", 18, "normal"))

            turtle.fd(40)
        elif i == '-':
            turtle.write('月', font=("Arial", 18, "normal"))

            turtle.fd(40)
        elif i == '*':
            turtle.write('日', font=("Arial", 18, "normal"))

            turtle.fd(40)
        elif i == '/':
            turtle.write('时', font=("Arial", 18, "normal"))

            turtle.fd(40)
        elif i == '!':
            turtle.write('分', font=("Arial", 18, "normal"))

            turtle.fd(40)
        elif i == '@':
            turtle.write('秒', font=("Arial", 18, "normal"))
        else:
            draw_digit(eval(i))


def main():
    turtle.setup(1360, 350, 100, 200)
    while True:
        turtle.reset()
        turtle.penup()
        turtle.fd(-600)
        turtle.pensize(8)
        turtle.tracer(False)
        turtle.hideturtle()
        draw_date(datetime.datetime.now().strftime('%Y+%m-%d*%H/%M!%S@'))
        time.sleep(10)
        turtle.done()


main()
