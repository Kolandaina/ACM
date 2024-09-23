#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
vector<vector<int>> g(N);
vector<int> size1(N);
int n;
inline int dfs(int p, int q)
{
    size1[p] = 1;
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
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (n % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (size1[i] % 2 == 0)
        {
            ans++;
        }
    }
    cout << ans - 1 << endl;
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