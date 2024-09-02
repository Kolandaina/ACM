import math
p = math.pi
r,x = map(int,input().split())
r1 = r * math.cos(x/r)
the = x/r1%(2*p)
s = the *r -x
if s> p*r:
    s = 2*p*r - s
print(s)
