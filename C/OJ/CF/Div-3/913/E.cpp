#include <bits/stdc++.h>
#define int long long
#define endl "\n"
std::vector<int> a = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
inline void slove()
{
    int n;
    std::cin >> n;
    int ans = 1;
    while (n)
    {
        ans *= a[n % 10];
        n /= 10;
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