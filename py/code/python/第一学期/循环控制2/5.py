x = int(input())
for i in range(x):
    y = int(input())
    z = 1
    for j in range(1, y+1):
        z *= j
    print(z)
