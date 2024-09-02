x = int(input())
b = 1
a = 1
for i in range(1, x+1):
    a *= i
    b += 1/a
print("{:.10f}".format(b))
