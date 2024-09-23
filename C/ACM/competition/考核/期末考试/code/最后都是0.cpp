#include <bits/stdc++.h>
#define int long long
const int inf = 1e16;

const int mod = 1e9 + 7;

void solved()
{
    int n;
    std::cin >> n;

    std::vector<int> f(n + 10, inf);

    f[0] = 0;
    for (int i = 1; i <= 9; i++) f[i] = 1;

    for (int i = 10; i <= n; i++)
    {
        int t = i;
        while (t)
        {
            f[i] = std::min(f[i], f[i - t % 10] + 1);
            t /= 10;
        }
    }

    std::cout << f[n];
}

// void setIO(std::string name = "") {
//     if (name.size()) {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // setIO("");

    int t = 1;
    // std::cin >> t;
    for (int i = 0; i < t; ++i) solved();

    return 0;
}