while 1:
    try:
        x = int(input())
        for i in range(1, x + 1):
            for j in range(0, x - i):
                print(" ", end="")
            for k in range(1, 2 * i):
                print("*", end="")
            print()
    except:
        break
