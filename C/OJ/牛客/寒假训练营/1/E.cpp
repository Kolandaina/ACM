#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int n, m, ans;
std::vector<int> a(N);
std::vector<std::pair<int, int>> g(N);
void dfs(int u)
{
    if (u == m + 1)
    {
        int t = 1;
        for (int i = 1; i <= n; i++)
            if (a[i] > a[1])
                t++;
        ans = std::min(ans, t);
        return;
    }
    int x = g[u].first, y = g[u].second;
    a[x] += 3;
    dfs(u + 1);
    a[x] -= 3;

    a[y] += 3;
    dfs(u + 1);
    a[y] -= 3;

    a[x] += 1;
    a[y] += 1;
    dfs(u + 1);
    a[x] -= 1;
    a[y] -= 1;
}
inline void slove()
{
    std::cin >> n >> m;
    ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> g[i].first >> g[i].second;
    }
    dfs(1);
    std::cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        slove();
    return 0;
}