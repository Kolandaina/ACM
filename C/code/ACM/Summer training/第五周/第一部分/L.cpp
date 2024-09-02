#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
vector<vector<int>> g(N);
int size1[N], size2[N];
int n, m;
inline int dfs1(int p, int q)
{
    size1[p] = 1;
    for (auto e : g[p])
    {
        if (e != q)
        {
            size1[p] += dfs1(e, p);
        }
    }
    return size1[p];
}
inline int dfs2(int p, int q)
{
    if (size1[p] == 1)
    {
        size2[p] = 1;
    }
    for (auto e : g[p])
    {
        if (e != q)
        {
            size2[p] += dfs2(e, p);
        }
    }
    return size2[p];
}
inline void slove()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }
    memset(size1, 0, sizeof(size1));
    memset(size2, 0, sizeof(size2));
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1, 0), dfs2(1, 0);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << size2[x] * size2[y] << endl;
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}