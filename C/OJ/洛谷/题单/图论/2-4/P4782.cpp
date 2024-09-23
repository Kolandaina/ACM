#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 4e6 + 5;
int n, m, dfncnt, cnt, sc;
int dfn[N], low[N], st[N], vis[N], scc[N];
std::vector<std::vector<int>> g(N);
void tarjan(int u)
{
    dfn[u] = low[u] = ++dfncnt;
    st[++cnt] = u;
    vis[u] = 1;
    for (auto v : g[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        }
        else if (vis[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        sc++;
        while (st[cnt] != u)
        {
            scc[st[cnt]] = sc;
            vis[st[cnt]] = 0;
            cnt--;
        }
        scc[st[cnt]] = sc;
        vis[st[cnt]] = 0;
        cnt--;
    }
}
inline void slove()
{
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, x, y;
        std::cin >> a >> x >> b >> y;
        if (x == 0 && y == 0)
        {
            g[a + n].push_back(b);
            g[b + n].push_back(a);
        }
        if (x == 0 && y == 1)
        {
            g[a + n].push_back(b + n);
            g[b].push_back(a);
        }
        if (x == 1 && y == 0)
        {
            g[a].push_back(b);
            g[b + n].push_back(a + n);
        }
        if (x == 1 && y == 1)
        {
            g[a].push_back(b + n);
            g[b].push_back(a + n);
        }
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (scc[i] == scc[i + n])
        {
            std::cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    std::cout << "POSSIBLE" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (scc[i] > scc[i + n])
        {
            std::cout << 1 << " ";
        }
        else
        {
            std::cout << 0 << " ";
        }
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--)
        slove();
    return 0;
}