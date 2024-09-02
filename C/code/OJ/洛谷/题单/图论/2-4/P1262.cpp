#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int M = 1e9 + 7;
std::stack<int> stk;
int n, m, p;
std::vector<std::vector<int>> g(N);
int dfn[N], low[N], dfncnt, scc[N], sc;
int in_stack[N], sum[N], ind[N], res[N];
void tarjan(int u)
{
    low[u] = dfn[u] = ++dfncnt;
    stk.push(u);
    in_stack[u] = 1;
    for (auto e : g[u])
    {
        if (!dfn[e])
        {
            tarjan(e);
            low[u] = std::min(low[u], low[e]);
        }
        else if (in_stack[e])
        {
            low[u] = std::min(low[u], dfn[e]);
        }
    }
    if (dfn[u] == low[u])
    {
        ++sc;
        while (!stk.empty())
        {
            int v = stk.top();
            stk.pop();
            scc[v] = sc;
            in_stack[v] = 0;
            res[sc] = std::min(res[sc], sum[v]);
            if (v == u)
                break;
        }
    }
}
inline void slove()
{
    std::cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = M, res[i] = M;
    }
    for (int i = 1; i <= p; i++)
    {
        int x, y;
        std::cin >> x >> y;
        sum[x] = y;
    }
    std::cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i] && sum[i] != M)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            std::cout << "NO" << endl
                      << i << endl;
            return;
        }
    }
    std::cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (auto e : g[i])
        {
            if (scc[i] != scc[e])
            {
                ind[scc[e]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= sc; i++)
    {
        if (!ind[i])
        {
            ans += res[i];
        }
    }
    std::cout << ans << endl;
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