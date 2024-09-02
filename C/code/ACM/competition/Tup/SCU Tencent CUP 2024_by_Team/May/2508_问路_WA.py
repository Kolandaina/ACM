

import math
r,x = map(int,input().split())
s = x*(1/math.cos(x/r)-1)
if s > 3.1415926535*r:
    s = 2*3.1415926535*r - s
print(s)

