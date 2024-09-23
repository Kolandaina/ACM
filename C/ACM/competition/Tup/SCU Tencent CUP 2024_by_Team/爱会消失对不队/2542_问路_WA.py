import math
r,x = map(int,input().split())
if x<r:
    x=x
else:
    x=2*r-x
    
s=x/r
print(abs(x*(1-1/math.cos(s))))
