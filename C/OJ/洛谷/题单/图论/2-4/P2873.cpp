#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 5e4 + 10;
int n, m, p, k;
int dfn[N], low[N], dfncnt, scc[N], sc;
int in_stack[N], deep[N];
std::stack<int> stk;
std::vector<std::vector<int>> g(N);
std::vector<std::vector<int>> gg(N);
std::vector<std::vector<int>> f(N + 1, std::vector<int>(32));
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
int lca(int x, int y)
{
    if (deep[x] < deep[y])
        std::swap(x, y);
    for (int i = k; i >= 0; i--)
    {
        if (deep[f[x][i]] >= deep[y])
        {
            x = f[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = k; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
void bfs(int s)
{
    std::queue<int> q;
    q.push(s);
    deep[s] = 1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto e : gg[t])
        {
            if (deep[e])
                continue;
            deep[e] = deep[t] + 1;
            f[e][0] = t;
            for (int i = 1; i <= k; i++)
            {
                f[e][i] = f[f[e][i - 1]][i - 1];
            }
            q.push(e);
        }
    }
}
std::vector<int> print(int ss)
{
    std::vector<long long> A;
    while (ss)
    {
        A.push_back(ss % 2);
        ss /= 2;
    }
    return A;
}
inline void slove()
{
    std::cin >> n >> m;
    std::map<std::pair<int, int>, int> mp;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (mp[{std::min(x, y), std::max(x, y)}] == 0)
        {
            g[x].push_back(y);
            g[y].push_back(x);
            mp[{std::min(x, y), std::max(x, y)}] = 1;
        }
    }
    k = (int)(std::log(n) / log(2)) + 1;
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto v : g[i])
        {
            if (scc[i] != scc[v])
            {
                gg[scc[v]].push_back(scc[i]);
                gg[scc[i]].push_back(scc[v]);
            }
        }
    }
    bfs(scc[1]);
    std::cin >> p;
    while (p--)
    {
        int a, b;
        std::cin >> a >> b;
        int t = lca(scc[a], scc[b]);
        int len = deep[scc[a]] + deep[scc[b]] - 2 * deep[t] + 1;
        std::vector<int> ans = print(len);
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            std::cout << ans[i];
        }
        std::cout << endl;
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