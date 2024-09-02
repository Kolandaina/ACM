n = int(input())
for i in range(n):
    x, y = input().split()
    m = max(int(x), int(y))
    n = min(int(x), int(y))
    a = m % n
    while a != 0:
        m = n
        n = a
        a = m % n
    print(n)
