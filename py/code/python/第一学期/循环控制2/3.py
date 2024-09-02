x = int(input())
while 1:
    if x % 2 == 0:
        x = x / 2
    elif x % 2 != 0:
        x = 3 * x + 1
    if x == 1:
        break
    print(int(x), end=",")
print(1)
