n,p = map(int,input().split())
w = []
d = dict()
for i in range(n):
    x = float(input())
    w.append(x)
    if x not in d:
        d[x] = 1
    else :
        d[x] += 1
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
    s = s % mod
    return s
        
def solve(x):
    f = 0
    c1,c2 = 0,0
    l,r = 0,n-1
    mid = (l+r)//2
    while(l <= r ):
        
        if x == w[mid]:
            f = 1
            mid -= 1
            while(w[mid] == x):
                mid -= 1
                if mid < 0:
                    mid = -1
                    break
            c1,c2 = mid+1,n-1-mid-d[x]
            break
        elif x > w[mid]:
            l = mid+1
            mid = (l+r)//2
        else :
            r = mid-1
            mid = (l+r) //2
    if f == 0:
        c1,c2 = l,n-l
        #print(c1,c2)
    if f == 1:
        #print(c1,c2,d[x])
        c = d[x]
        if c1== 0 or c2 == 0:
            res = (ffpow(c)-1)*ffpow(c1)*ffpow(c2)
        else :res = (ffpow(c1)-1)*(ffpow(c2)-1) + (ffpow(c)-1)*ffpow(c1)*ffpow(c2)
        res = res%mod
        print(res)
    else :
        res = (ffpow(c1)-1) * (ffpow(c2)-1)
        res = res % mod
        print(res)
        
for i in range(p):
    x = float(input())
    solve(x)
