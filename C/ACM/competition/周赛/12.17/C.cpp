#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::vector<int> res(n + 1);
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        maxn = std::max(maxn, a[i]);
        if (maxn == a[i])
            res[i] = a[i] * i;
        else
            res[i] = res[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += res[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cout << res[i] << " ";
    }
    std::cout << endl;
    std::cout << ans % mod << endl;
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