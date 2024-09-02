while 1:
    flag = 1
    a = int(input())
    print("{0:}:".format(a), end="")
    for i in range(2, a+1):
        b = 0
        if 500 < i < 8120 or i > 8130:
            continue
        for j in range(1, i//2+1):
            if i % j == 0:
                b += j
        if i == b:
            print(" {0:}".format(i), end="")
            flag = 0
    if flag:
        print(" NULL")
    print()

