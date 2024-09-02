#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 3e5 + 10;
std::vector<std::vector<int>> g(N);
std::vector<std::vector<int>> gg(N);
int n, m;
int dfn[N], low[N], in_stack[N], scc[N], dfncnt, sc;
int deep1[N], deep2[N];
std::stack<int> stk;
void tarjan(int u, int fa)
{
    low[u] = dfn[u] = ++dfncnt;
    stk.push(u);
    in_stack[u] = 1;
    for (auto e : g[u])
    {
        if (e == fa)
            continue;
        if (!dfn[e])
        {
            tarjan(e, u);
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
            if (v == u)
                break;
        }
    }
}
int bfs1(int s)
{
    std::queue<int> q;
    q.push(s);
    deep1[s] = 1;
    int maxn = 0, sum = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto e : gg[t])
        {
            if (!deep1[e])
            {
                deep1[e] = deep1[t] + 1;
                if (deep1[e] > maxn)
                {
                    maxn = deep1[e];
                    sum = e;
                }
                q.push(e);
            }
        }
    }
    return sum;
}
int bfs2(int s)
{
    std::queue<int> q;
    q.push(s);
    deep2[s] = 1;
    int maxn = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto e : gg[t])
        {
            if (!deep2[e])
            {
                deep2[e] = deep2[t] + 1;
                if (deep2[e] > maxn)
                {
                    maxn = deep2[e];
                }
                q.push(e);
            }
        }
    }
    return maxn;
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
        {
            tarjan(i, 0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        std::cout << scc[i] << " ";
    }
    std::cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (auto e : g[i])
        {
            if (scc[i] != scc[e])
            {
                gg[scc[i]].push_back(scc[e]);
                gg[scc[e]].push_back(scc[i]);
            }
        }
    }
    std::cout << std::max(bfs2(bfs1(1)) - 1, 0ll) << endl;
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