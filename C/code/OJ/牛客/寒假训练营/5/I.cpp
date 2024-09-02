#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int t, a, k;
    std::cin >> t >> a >> k;
    if (a >= std::min(-k, t - k) && a <= std::max(k, t + k))
        std::cout << std::abs(a) + std::abs(t - a) << endl;
    else
        std::cout << 2 * std::abs(t - a) + abs(t) << endl;
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