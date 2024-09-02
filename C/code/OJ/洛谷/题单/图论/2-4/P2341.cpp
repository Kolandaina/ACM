#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
std::vector<std::vector<int>> g(N);
int n, m;
int dfn[N], low[N], dfncnt, in_stack[N];
int scc[N], sc;
int sz[N], out[N];
std::stack<int> stk;
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
            sz[sc]++;
            in_stack[v] = 0;
            if (v == u)
                break;
        }
    }
}
inline void slove()
{
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto e : g[i])
        {
            if (scc[i] != scc[e])
            {
                out[scc[i]]++;
            }
        }
    }
    for (int i = 1; i <= sc; i++)
    {
        if (out[i] == 0)
        {
            ans = sz[i];
            cnt++;
        }
    }
    if (cnt == 1)
        std::cout << ans << endl;
    else
        std::cout << 0 << endl;
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