import math
r,x = map(int,input().split())
if x >= r:
	r = 2*r -x
s = x*(1/math.cos(x/r)-1)
print(s)