#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6;
int n, m, s, k, res;
int a[N], ans[N];
vector<vector<int>> g(N + 1);
vector<int> deep(N + 1);
int x[N], y[N], val1[N], val2[N];
std::vector<std::vector<int>> f(N + 1, std::vector<int>(32));
void bfs()
{
    queue<int> q;
    q.push(1);
    deep[1] = 1;
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
            for (int i = 1; i < k; i++)
            {
                f[e][i] = f[f[e][i - 1]][i - 1];
            }
            q.push(e);
        }
    }
}
int lca(int x, int y)
{
    if (deep[x] < deep[y])
        swap(x, y);
    for (int i = k; i >= 0; i--)
    {
        if (deep[f[x][i]] >= deep[y])
            x = f[x][i];
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
void dfs(int p)
{
    for (auto e : g[p])
    {
        if (deep[e] <= deep[p])
            continue;
        dfs(e);
        ans[p] += ans[e];
    }
}
inline void slove()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x[i] >> y[i] >> val1[i] >> val2[i];
        g[x[i]].push_back(y[i]);
        g[y[i]].push_back(x[i]);
    }
    k = (int)(std::log(n) / log(2)) + 1;
    bfs();
    for (int i = 1; i <= n - 1; i++)
    {
        ans[i]++, ans[i + 1]++;
        int t = lca(i, i + 1);
        ans[t] -= 2;
    }
    dfs(1);
    for (int i = 1; i < n; i++)
    {
        int as;
        if (deep[x[i]] > deep[y[i]])
            as = ans[x[i]];
        else
            as = ans[y[i]];
        res += min(as * val1[i], val2[i]);
    }
    cout << res << endl;
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