#include <bits/stdc++.h>

#define int long long

const int mod = 998244353;
const int max1 = 2e6 + 7;
int f[max1][2];

signed main()
{
    int n, m;
    std::cin >> n >> m;

    f[1][1] = m;
    f[1][0] = 0;

    for (int i = 2; i <= n + 1; i++)
    {
        f[i][0] = (f[i - 1][1] * (m - 1) % mod + f[i - 1][0] * (m - 2) % mod) % mod;
        f[i][1] = f[i - 1][0];
    }

    std::cout << f[n][0] % mod;

    return 0;
}
