def out(a,b):
    for i in range(a,(b-a)//2+1+a):
        print(i,b+a-i)

flag = [True for i in range(int(2e6+5))]
flag[0] = flag[1] = False
for i in range(2,int(2e6+5)):
    if flag[i] == True:
        j = i+i
        while j<int(2e6+5):
            flag[j] = False
            j += i
prime = [i for i in range(int(2e6+5)) if flag[i] == True]
primes = set(prime)
t = int(input());f = 0
for _ in range(t):
    n = int(input())
    if 1+2*n in prime: out(1,2*n)
    else:
        for i in prime:
            a = i-1
            if  a+1+2*n in primes: f = 1;break
        else:print(-1)
        if f == 1:
            out(1,a)
            out(a+1,2*n)


