#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int ans = 0;
    if (a == 150)
        ans += 1;
    if (a == 200)
        ans += 2;
    if (b > 33 && b <= 40)
        ans += 1;
    if (b == 45)
        ans += 2;
    if (c > 33 && c <= 40)
        ans += 1;
    if (c == 45)
        ans += 2;
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