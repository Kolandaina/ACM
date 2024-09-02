#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
int n, m;
bool isbridge[N];
int low[N], dfn[N], dfs_clock, cnt_bridge, father[N];
std::vector<std::vector<int>> g(N);
void tarjan(int u, int fa)
{
    father[u] = fa;
    low[u] = dfn[u] = ++dfs_clock;
    for (auto v : g[u])
    {
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = std::min(low[u], low[v]);
            if (low[v] > dfn[u])
            {
                isbridge[v] = true;
                ++cnt_bridge;
            }
        }
        else if (dfn[v] < dfn[u] && v != fa)
        {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
}
inline void slove()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i, 0);
    }
    std::vector<std::pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (isbridge[i])
            ans.push_back({std::min(i, father[i]), std::max(i, father[i])});
    }
    sort(ans.begin(), ans.end());
    for (auto res : ans)
    {
        std::cout << res.first << ' ' << res.second << endl;
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