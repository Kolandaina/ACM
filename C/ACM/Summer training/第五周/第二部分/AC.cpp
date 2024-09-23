#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N = 1e5 + 10;
int p[N], n, m, k, q;
vector<std::vector<int>> g(N + 1);
vector<int> deep(N + 1);
vector<int> size1(N + 1);
vector<std::vector<int>> f(N + 1, std::vector<int>(32));
vector<std::vector<int>> res(N + 1, std::vector<int>(32));
map<pair<int, int>, int> mp;
struct node
{
    int x, y;
    int d;
} v[4 * N];
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        return s1.d < s2.d;
    }
};
inline int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
inline void kruskal()
{
    sort(v + 1, v + m + 1, node1());
    for (int i = 1; i <= m; i++)
    {
        if (find(v[i].x) != find(v[i].y))
        {
            p[find(v[i].x)] = find(v[i].y);
            g[v[i].x].push_back(v[i].y);
            g[v[i].y].push_back(v[i].x);
            mp[{v[i].x, v[i].y}] = mp[{v[i].y, v[i].x}] = v[i].d;
        }
    }
}
inline void bfs(int r)
{
    std::queue<int> q;
    q.push(r);
    deep[r] = 1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto e : g[t])
        {
            if (deep[e])
                continue;
            deep[e] = deep[t] + 1;
            f[e][0] = t;
            res[e][0] = mp[{e, t}];
            for (int i = 1; i <= k; i++)
            {
                f[e][i] = f[f[e][i - 1]][i - 1];
                res[e][i] = max(res[e][i - 1], res[f[e][i - 1]][i - 1]);
            }
            q.push(e);
        }
    }
}
inline int lca(int x, int y)
{
    int ans = 0;
    if (deep[x] < deep[y])
        std::swap(x, y);
    for (int i = k; i >= 0; i--)
    {
        if (deep[f[x][i]] >= deep[y])
        {
            ans = max(ans, res[x][i]);
            x = f[x][i];
        }
    }
    if (x == y)
    {
        return ans;
    }
    for (int i = k; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
        {
            ans = max(ans, res[x][i]);
            ans = max(ans, res[y][i]);
            x = f[x][i], y = f[y][i];
        }
    }
    ans = max(ans, res[x][0]);
    ans = max(ans, res[y][0]);
    return ans;
}
inline void slove()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i].x >> v[i].y >> v[i].d;
    }
    kruskal();
    k = (int)(std::log(n) / log(2)) + 1;
    for (int i = 1; i <= n; i++)
    {
        if (!deep[i])
        {
            bfs(i);
        }
    }
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (find(x) != find(y))
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << lca(x, y) << endl;
        }
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}