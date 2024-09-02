#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int a, b, n;
    std::cin >> a >> b >> n;
    int a1 = -1, b1 = -1, mn = 1000000;
    for (int i = 1; i <= n - 1; i++)
    {
        int j = n - i;
        if (a != i && a % i == 0 && b % j == 0 && b != j)
        {
            int aa = a / i, bb = b / j, res = abs(aa - bb);
            if (mn > res) a1 = i, b1 = j, mn = res;
        }
    }
    if (a1 == -1 && b1 == -1)
        std::cout << "No Solution";
    else
        std::cout << a1 << " " << b1;
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