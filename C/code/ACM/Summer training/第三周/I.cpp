#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6;
int n, m, s, k;
vector<vector<int>> g(N + 1);
vector<int> deep(N + 1);
std::vector<std::vector<int>> f(N + 1, std::vector<int>(32));
inline void bfs()
{
    queue<int> q;
    q.push(s);
    deep[s] = 1;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (auto e : g[t])
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
inline int lca(int x, int y)
{
    if (deep[x] < deep[y])
        swap(x, y);
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
            x = f[x][i], y = f[y][i];
        }
    }
    return f[x][0];
}
inline void slove()
{
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    k = (int)(std::log(n) / log(2)) + 1;
    bfs();
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
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