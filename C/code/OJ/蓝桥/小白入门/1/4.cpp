#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void write(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
inline void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    __int128 ans = 0, s = a[0];
    for (int i = 1; i < n; i++)
    {
        ans += (__int128)a[i] * s;
        s += a[i];
    }
    write(ans);
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}