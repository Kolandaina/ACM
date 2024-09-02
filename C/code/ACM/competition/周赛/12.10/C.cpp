#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
std::vector<std::vector<int>> g(N);
std::vector<std::vector<int>> dp(N, std::vector<int>(3));
inline void dfs(int x, int y)
{
    dp[x][0] = dp[x][1] = 1;
    for (auto e : g[x])
    {
        if (e == y)
            continue;
        dfs(e, x);
        dp[x][0] = dp[x][0] % mod * (dp[e][0] + dp[e][1]) % mod;
        dp[x][1] = (dp[x][1] % mod * dp[e][0]) % mod;
    }
}
inline void slove()
{
    int n;
    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int ans = (dp[1][0] + dp[1][1]) % mod;
    std::cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--)
        slove();
    return 0;
}