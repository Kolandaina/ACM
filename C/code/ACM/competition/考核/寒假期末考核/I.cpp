#include <bits/stdc++.h>
#define endl "\n"
const int N = 1e4;
inline void slove()
{
    int n;
    std::cin >> n;
    int ans = 1;
    for (int i = 2; i * i <= n; i++)
    {
        int res = 1;
        while (n % i == 0)
        {
            res++;
            n /= i;
        }
        ans *= res;
    }
    if (n > 1) ans *= 2;
    std::cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) slove();
    return 0;
}