#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
std::vector<std::vector<int>> g(N);
std::vector<std::vector<int>> e(N);
std::vector<std::vector<int>> gg(N);
int n, m;
int dfn[N], low[N], dfncnt, in_stack[N];
int scc[N], sc;
int dis[N], ga[N], a[N];
int eu[N], ev[N];
int ind[N], ans[N];
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
            ga[sc] += a[v];
            in_stack[v] = 0;
            if (v == u)
                break;
        }
    }
}
void topo()
{
    std::queue<int> q;
    int cnt = 0;
    for (int i = 1; i <= sc; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans[++cnt] = u;
        for (auto v : e[u])
        {
            ind[v]--;
            if (ind[v] == 0)
            {
                q.push(v);
            }
        }
    }
}
inline void slove()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> eu[i] >> ev[i];
        g[eu[i]].push_back(ev[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (scc[eu[i]] != scc[ev[i]])
        {
            ind[scc[ev[i]]]++;
            e[scc[eu[i]]].push_back(scc[ev[i]]);
            gg[scc[ev[i]]].push_back(scc[eu[i]]);
        }
    }
    topo();
    for (int i = 1; i <= sc; i++)
    {
        int w = ans[i];
        dis[w] = ga[w];
        for (auto v : gg[w])
        {
            dis[w] = std::max(dis[w], dis[v] + ga[w]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= sc; i++)
    {
        sum = std::max(sum, dis[i]);
    }
    std::cout << sum << endl;
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