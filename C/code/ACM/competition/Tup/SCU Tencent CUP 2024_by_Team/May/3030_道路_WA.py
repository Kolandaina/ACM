def dfs(a,depth):
    if len(city[a]) == 0:
        deep.append(depth);return
    else:
        for i in city[a]:
            if vis[a] == 0:
                vis[a] = 1;dfs(i,depth+1)
            else:
                dfs(i,depth)

n = int(input())
vis = [0]*(n+1)
vis[1] = 1
city = [[] for i in range(n+1)]
deep = []
father = [0,0]+list(map(int,input().split()))
for i in range(2,n+1):
    city[father[i]].append(i)
if n == 1:print(0)
else:
    dfs(1,1)
    print(max(deep)-min(deep))
