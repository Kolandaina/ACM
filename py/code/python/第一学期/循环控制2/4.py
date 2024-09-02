a = int(input())
m = []
for i in range(2, a):
    flag = 1
    for j in range(2, int(i**0.5)+1):
        if i % j == 0:
            flag = 0
    if flag:
        m.append(i)
for i in range(len(m)):
    if a-m[i] in m:
        print("{} = {} + {}".format(a, m[i], a-m[i]))
        break
"""def a(i):
    flag = 1
    if i == 1:
        return 0
    for j in range(2, int(i**0.5)+1):
        if i % j == 0:
            flag = 0
            break
    return flag
n = int(input())
for i in range(1,n//2+1):
    if a(i) and a(n-i):
        print("%d = %d + %d" % (n, i, n-i))
        break
"""