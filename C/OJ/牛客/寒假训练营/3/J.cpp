#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int ksm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inv(int x) { return ksm(x, mod - 2); }
inline void slove()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> g(N + 1);
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        std::cin >> x >> y;
        g[x].push_back(n + y);
        g[n + y].push_back(x);
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int res = 1;
        for (auto e : g[i]) res = res * (1 - inv(g[e].size()) + mod) % mod;
        ans1 = (ans1 + 1 - res + mod) % mod;
    }
    for (int i = n + 1; i <= n + m; i++)
    {
        int res = 1;
        for (auto e : g[i]) res = res * (1 - inv(g[e].size()) + mod) % mod;
        ans2 = (ans2 + 1 - res + mod) % mod;
    }
    std::cout << "modint" << endl;
    std::cout << ans1 << " " << ans2 << endl;
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