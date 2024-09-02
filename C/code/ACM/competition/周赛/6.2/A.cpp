#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void solve()
{
    int n;
    std::cin >> n;
    int ans = 0, cnt = 0;
    while (n > 0)
    {
        cnt++;
        if (n % 3 == 1 && ans == 0)
        {
            ans = cnt;
        }
        n -= std::ceil(n / 3.0);
    }
    std::cout << cnt << " " << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) solve();
    return 0;
}