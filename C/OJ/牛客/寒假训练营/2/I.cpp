#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    if (n == 1)
    {
        std::cout << 0 << endl;
        return;
    }
    std::sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] * 2 * i;
    }
    std::cout << ans * 2 << endl;
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