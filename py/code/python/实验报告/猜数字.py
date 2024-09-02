import random as r
x = int(input())
y = r.randint(0, 9)
while 1:
    if x > y:
        print("猜大了")
    elif x < y:
        print("猜小了")
    elif x == y:
        print("猜对了")
        break
    x = int(input())
