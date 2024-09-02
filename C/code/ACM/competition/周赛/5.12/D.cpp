#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
std::vector<std::vector<int>> ans(110, std::vector<int>(N));
inline void slove()
{
    int n, q, m;
    std::cin >> n >> q >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ans[a[i]][i]++;
    }
    for (int i = 1; i <= q; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans[i][j] += ans[i - 1][j];
        }
    }
    while (m--)
    {
        int l, r;
        std::cin >> l >> r;
        int maxn = 0;
        for (int i = 1; i <= q; i++)
        {
            maxn = std::max(maxn, ans[i][r] - ans[i][l - 1]);
        }
        std::cout << maxn << endl;
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}