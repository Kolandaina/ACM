import math
r,x = map(int,input().split())
s=x/r
print(abs(x*(1-1/math.cos(s))))
