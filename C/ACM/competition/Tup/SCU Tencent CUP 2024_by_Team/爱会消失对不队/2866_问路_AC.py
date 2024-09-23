import math
r,x = map(int,input().split())
pai = math.pi
s=x/r
b=x
while b>2*pai*r*math.cos(s):
    b-=2*pai*r*math.cos(s)
c=b/(r*math.cos(s))
a1=abs(r*(s-c))
a2=2*pai*r-a1
print(min(a1,a2))
