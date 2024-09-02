N, k = 10 ** 5
p, deep = [0] * N
f, res = [[0] * 32 for _ in range(N)]
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    v = [a[0]]
    for i in range(1, n):
        v.extend([1, a[i]]) if a[i] < a[i - 1] else v.append(a[i])
    print(len(v), *v)

for s in [*open(0)][2::2]:
    *a, = map(int, s.split())
    r = []
    for x, y in zip([0] + a, a):
        r += [y] * (1 + (x > y))
    print(len(r), *r)


def lca(x, y):
    ans = 0
    if deep[x] < deep[y]:
        x, y = y, x
    for i in range(k, -1, -1):
        if deep[f[x][i]] >= deep[y]:
            ans = max(ans, res[x][i])
            x = f[x][i]
    if x == y:
        return ans
    for i in range(k, -1, -1):
        if f[x][i] != f[y][i]:
            ans = max(ans, max(res[x][i], res[y][i]))
            x, y = f[x][i], f[y][i]
    ans = max(ans, max(res[x][0], res[y][0]))
    return ans
