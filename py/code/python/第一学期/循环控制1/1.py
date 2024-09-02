a = int(input())
for a in range(a, 0, -1):
    i = 0
    b = 0
    w = [int(x)for x in input().split()]
    for c in w:
          b += c
          i += 1
    print(b/i)
