
import math
r,x = map(int,input().split())
s = x*(1/math.cos(x/r)-1)
print(s)

