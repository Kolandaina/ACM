#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    long long n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::vector<int> dp(n + 1);
    std::vector<int> maxn(n + 1, INT_MIN);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = std::max(dp[i - 1], i + maxn[a[i]]);
        maxn[a[i]] = std::max(maxn[a[i]], dp[i - 1] - i + 1);
    }
    std::cout << dp[n] << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        slove();
    return 0;
}