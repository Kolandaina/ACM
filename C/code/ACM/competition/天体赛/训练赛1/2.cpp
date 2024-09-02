#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n, m, k;
    std::string x;
    std::cin >> n >> x >> m >> k;
    if (k == n)
        std::cout << "mei you mai " << x << " de";
    else if (k == m)
        std::cout << "kan dao le mai " << x << " de";
    else
        std::cout << "wang le zhao mai " << x << " de";
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