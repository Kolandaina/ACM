#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

inline void slove()
{
    int n, m1, m2, m3;
    std::cin >> n >> m1 >> m2 >> m3;
    std::vector<int> v1(n + 1), w1(n + 1), v2(n + 1), w2(n + 1), v3(n + 1), w3(n + 1);
    for (int i = 1; i <= n; i++)std::cin >> v1[i] >> w1[i];
    for (int i = 1; i <= n; i++)std::cin >> v2[i] >> w2[i];
    for (int i = 1; i <= n; i++)std::cin >> v3[i] >> w3[i];
    std::vector<int> dp1(n + 1), dp2(n + 1), dp3(n + 1);
    dp1[0] = dp2[0] = dp3[0] = 0;
    for (int i = 1; i <= m1; i++)
    {
        for (int j = n; j > v1[i]; j--)
        {
            dp1[j] = std::max(dp1[j], dp1[j - v1[i]] + w1[i]);
        }
    }
    for (int i = 1; i <= m2; i++)
    {
        for (int j = n; j > v2[i]; j--)
        {
            dp2[j] = std::max(dp2[j], dp2[j - v1[i] + w1[i]]);
        }
    }
    for (int i = 1; i <= m3; i++)
    {
        for (int j = n; j > v3[i]; j--)
        {
            dp3[j] = std::max(dp3[j], dp3[j - v1[i] + w1[i]]);
        }
    }
    std::vector<int> ans1(n + 1), ans2(n + 1);
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