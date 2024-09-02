#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, m, s, k;
vector<vector<int>> g(N + 1);
vector<int> size1(N + 1);
vector<int> father(N + 1);
int ans[N];
inline int dfs(int p, int q)
{
    size1[p] = 1;
    father[p] = q;
    for (auto e : g[p])
    {
        if (e != q)
        {
            size1[p] += dfs(e, p);
        }
    }
    return size1[p];
}
inline void slove()
{
    cin >> n >> s >> m;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(s, 0);
    while (m--)
    {
        int x;
        cin >> x;
        if (ans[x] != 0)
        {
            cout << ans[x] << endl;
            continue;
        }
        int res = size1[x] * size1[x];
        for (auto e : g[x])
        {
            if (e != father[x])
            {
                res -= size1[e] * size1[e];
            }
        }
        ans[x] = res;
        cout << res << endl;
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