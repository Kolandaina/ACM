#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n;
    std::cin >> n;
    if (n % 4 == 0)
    {
        int res = n / 4;
        if (res % 2 == 1)
        {
            std::cout << 2 << " " << -2 * res;
            for (int i = 0; i < 3 * res - 2; i++) std::cout << " " << 1;
            for (int i = 0; i < res; i++) std::cout << " " << -1;
        }
        else
        {
            std::cout << -2 << " " << -2 * res;
            for (int i = 0; i < 3 * res; i++) std::cout << " " << 1;
            for (int i = 0; i < res - 2; i++) std::cout << " " << -1;
        }
        std::cout << endl;
    }
    else
    {
        std::cout << "NO" << endl;
    }
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