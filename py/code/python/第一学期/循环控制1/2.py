a = int(input())
for a in range(a, 0, -1):
    b, c = input().split()
    b = int(b)
    c = int(c)
    flag = 1
    for i in range(b, c+1):
        if i % 3 == 2 and i % 7 == 1:
            print(i, end=" ")
            flag = 0
    if flag:
        print("none")
