from turtle import *
from math import cos, pi

penup()
goto(-300, 200)

pendown()
pencolor("red")
fillcolor("red")
begin_fill()
goto(300, 200)
goto(300, -200)
goto(-300, -200)
goto(-300, 200)
end_fill()

penup()
goto(-260, 120)

pendown()
pencolor("yellow")
fillcolor("yellow")
begin_fill()
for i in range(5):
    fd(120 * cos(18 * pi / 180))
    right(144)
end_fill()

penup()
goto(-200, 100)
right(-30)
fd(96.5)
right(-18)
pendown()
pencolor("yellow")
fillcolor("yellow")
begin_fill()
for i in range(5):
    fd(40 * cos(18 * pi / 180))
    right(144)
end_fill()

penup()
goto(-200, 100)
seth(0)
right(-8)
fd(121.5)
right(-18)
pendown()
pencolor("yellow")
fillcolor("yellow")
begin_fill()
for i in range(5):
    fd(40 * cos(18 * pi / 180))
    right(144)
end_fill()

penup()
goto(-200, 100)
seth(0)
right(16)
fd(125.5)
pendown()
pencolor("yellow")
fillcolor("yellow")
begin_fill()
for i in range(5):
    fd(40 * cos(18 * pi / 180))
    right(144)
end_fill()

penup()
goto(-200, 100)
seth(0)
right(39)
fd(108.5)
pendown()
pencolor("yellow")
fillcolor("yellow")
begin_fill()
for i in range(5):
    fd(40 * cos(18 * pi / 180))
    right(144)
end_fill()
hideturtle()
