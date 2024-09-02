import math
r,x = map(int,input().split())
pai = math.pi
s=x/r
a1=abs(x*(1-1/math.cos(s)))
a2=2*pai*r-a1
print(min(a1,a2))

