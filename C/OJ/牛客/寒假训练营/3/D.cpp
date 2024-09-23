#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
inline void slove()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int maxn = *std::max_element(a.begin(), a.end());
    if (maxn <= 0)
    {
        std::cout << maxn << endl;
        return;
    }
    if (k == 0)
    {
        int ans = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            res += a[i];
            ans = std::max(ans, res);
            if (res < 0) res = 0;
        }
        std::cout << ans << endl;
        return;
    }
    else
    {
        int pre = 0;
        for (int i = 1; i < n; i++)
        {
            std::vector<int> b = a;
            std::swap(b[i], b[i - 1]);
            int ans = 0, res = 0;
            for (int i = 0; i < n; i++)
            {
                res += b[i];
                ans = std::max(ans, res);
                if (res < 0) res = 0;
            }
            pre = std::max(pre, ans);
        }
        std::cout << pre << endl;
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