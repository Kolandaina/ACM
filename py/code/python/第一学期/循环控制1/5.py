while 1:
    x = int(input())
    if 90 <= x <= 100:
        print("A")
    elif 80 <= x <= 89:
        print("B")
    elif 70 <= x <= 79:
        print("C")
    elif 60 <= x <= 69:
        print("D")
    elif 0 <= x <= 59:
        print("E")
    elif x > 100:
        print("data error!")
    elif x < 0:
        print("end")
        break