#include <bits/stdc++.h>
#define int long long
const int inf = 1e16;

void solved()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<int, 3>> p(n);
    std::vector<std::array<int, 4>> k(m);

    for (int i = 0; i < n; i++)
        for (auto &i : p[i]) std::cin >> i;
    for (int i = 0; i < m; i++)
        for (auto &i : k[i]) std::cin >> i;

    int res = inf;
    int lim = (1 << m);
    for (int i = 0; i < lim; i++)
    {
        int ans = 0;
        std::vector<int> a(101);
        for (int j = 0; j < m; j++)
        {
            if ((1 << j) & i)
            {
                ans += k[j][3];
                for (int t = k[j][0]; t <= k[j][1]; t++) a[t] += k[j][2];
            }
        }
        bool tag = true;
        for (int j = 0; j < n; j++)
        {
            if (!tag) break;
            for (int t = p[j][0]; t <= p[j][1]; t++)
                if (a[t] < p[j][2])
                {
                    tag = false;
                    break;
                }
        }
        if (tag) res = std::min(res, ans);
    }
    std::cout << res;
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