#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int a, b;
    std::cin >> a >> b;
    auto sum = [&](int x) -> int {
        int res = 0;
        while (x)
        {
            res += x % 10;
            x /= 10;
        }
        return res;
    };
    int x = sum(a), y = sum(b);
    if (a % y == 0 && b % x == 0)
    {
        if (a > b)
            std::cout << 'A' << endl;
        else
            std::cout << 'B' << endl;
    }
    else if (a % y == 0)
        std::cout << 'A' << endl;
    else if (b % x == 0)
        std::cout << 'B' << endl;
    else
    {
        if (a > b)
            std::cout << 'A' << endl;
        else
            std::cout << 'B' << endl;
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