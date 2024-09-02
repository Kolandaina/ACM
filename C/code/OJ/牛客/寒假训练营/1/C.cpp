#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    int n, m, w;
    std::cin >> n >> m >> w;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i] + a[i - 1];
    }
    std::vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = a[i] + a[i - 1];
    }
    while (m--)
    {
        int x;
        std::cin >> x;
        int t = std::min(1ll * n, x / w);
        std::cout << a[n - t] + w << endl;
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