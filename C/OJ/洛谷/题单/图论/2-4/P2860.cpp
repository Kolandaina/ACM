#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
std::vector<std::vector<int>> g(N);
int n, m;
int dfn[N], low[N], scc[N], in_stack[N], dfncnt, sc;
int ind[N];
std::stack<int> stk;
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++dfncnt;
    stk.push(u);
    in_stack[u] = 1;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = std::min(low[u], low[v]);
        }
        else if (in_stack[v])
        {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        sc++;
        while (!stk.empty())
        {
            int v = stk.top();
            stk.pop();
            scc[v] = sc;
            in_stack[v] = 0;
            if (v == u)
                break;
        }
    }
}
inline void slove()
{
    std::cin >> n >> m;
    std::map<std::pair<int, int>, int> mp;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        if (mp[{u, v}] == 0)
        {
            g[u].push_back(v);
            g[v].push_back(u);
            mp[{u, v}] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto e : g[i])
        {
            if (scc[i] != scc[e])
            {
                ind[scc[e]]++;
                ind[scc[i]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= sc; i++)
    {
        if (ind[i] / 2 == 1)
            ans++;
    }
    std::cout << (ans + 1) / 2 << endl;
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