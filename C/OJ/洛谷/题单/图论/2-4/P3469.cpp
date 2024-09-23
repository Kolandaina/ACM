#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
int n, m;
int dfn[N], low[N], dfncnt, scc[N], sc;
int in_stack[N];
std::stack<int> stk;
std::vector<std::vector<int>> g(N);
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
            in_stack[v] = 0;
            scc[v] = sc;
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
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i, 0);
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