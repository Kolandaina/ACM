#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> a(n);
    std::vector<int> sum(n + 1);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].first >> a[i].second;
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + a[i].second;
    }
    int ans = m;
    for (int i = 0; i < n; i++)
    {
        if (a[i].first - sum[i + 1] <= m)
        {
            ans = sum[i + 1] + m;
        }
    }
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