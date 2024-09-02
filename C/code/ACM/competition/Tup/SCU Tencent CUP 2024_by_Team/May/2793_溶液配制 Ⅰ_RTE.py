n,p = map(int,input().split())
w = []
for i in range(n):
    x = float(input())
    w.append(x)
w.sort()
mod = int(1e9+7)

def ffpow(c1):
    a = 2
    s = 1
    while(c1 >0):
        if c1 & 1 == 1:
            s *= a
            s = s%mod
        c1 >>= 1
        a = a*a%mod
    return s
        
def solve(x):
    f = 0
    c1,c2 = 0,0
    l,r = 0,n-1
    mid = (l+r)//2
    while(l <= r ):
        if x == w[mid]:
            f = 1
            c1,c2 = mid,n-1-mid
            break
        elif x > w[mid]:
            l = mid+1
            mid = (l+r)//2
        else :
            r = mid-1
            mid = (l+r) - 1
    if f == 0:
        c1,c2 = l,n-l
    if f == 1:
        res = 1 + ffpow(c1)*ffpow(c2)
        if c1 == 0 or c2 == 0:
            res -= 1
        print(res)
    else :
        res = (ffpow(c1)-1) * (ffpow(c2)-1)
        print(res)
        
for i in range(p):
    x = float(input())
    solve(x)
