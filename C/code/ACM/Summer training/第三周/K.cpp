#include <bits/stdc++.h>
using namespace std;
#define int  long long
#define endl "\n"
const int N = 1e5 + 10;
int n, m, s, k;
std::vector<std::vector<int>> g(N + 1);
std::vector<int> deep(N + 1);
std::vector<int> size1(N + 1);
std::vector<std::vector<int>> f(N + 1, std::vector<int>(32));
inline void bfs()
{
    std::queue<int> q;
    q.push(1);
    deep[1] = 1;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (auto e : g[t])
        {
            if (deep[e]) continue;
            deep[e] = deep[t] + 1;
            f[e][0] = t;
            for (int i = 1; i <= k; i++) f[e][i] = f[f[e][i - 1]][i - 1];
            q.push(e);
        }
    }
}
inline int lca(int x, int y)
{
    if (deep[x] < deep[y]) std::swap(x, y);
    for (int i = k; i >= 0; i--)
    {
        if (deep[f[x][i]] >= deep[y]) x = f[x][i];
    }
    if (x == y) return x;
    for (int i = k; i >= 0; i--)
    {
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
inline int dfs(int p, int q)
{
    size1[p] = 1;
    for (auto e : g[p])
    {
        if (e != q) size1[p] += dfs(e, p);
    }
    return size1[p];
}
inline int jump(int x, int len)
{
    int res = x;
    for (int i = k; i >= 0; i--)
    {
        if (deep[x] - deep[f[res][i]] <= len) res = f[res][i];
    }
    return res;
}
inline void slove()
{
    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    k = (int)(std::log(n) / log(2)) + 1;
    bfs();
    dfs(1, 0);
    std::cin >> m;
    while (m--)
    {
        int x, y;
        std::cin >> x >> y;
        if (x == y)
        {
            std::cout << size1[1] << endl;
            continue;
        }
        int t = lca(x, y);
        int len = deep[x] + deep[y] - 2 * deep[t] + 1;
        if (len % 2 == 0)
        {
            std::cout << 0 << endl;
            continue;
        }
        len = len / 2;
        if (deep[x] - deep[t] == len)
        {
            int ans =
                size1[1] - size1[jump(x, len - 1)] - size1[jump(y, len - 1)];
            std::cout << ans << endl;
        }
        else
        {
            if (deep[x] < deep[y]) std::swap(x, y);
            int ans = size1[jump(x, len)] - size1[jump(x, len - 1)];
            std::cout << ans << endl;
        }
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) slove();
    return 0;
}