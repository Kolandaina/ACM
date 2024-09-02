#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
std::vector<bool> vis(N, true);
std::vector<int> ans(N, 1);
void init(int n)
{
    for (int i = 2; i <= n / i; i++)
    {
        if (vis[i])
        {
            for (int j = i * i; j <= n; j += i) vis[j] = false;
        }
    }
}
inline void slove()
{
    int n;
    std::cin >> n;
    init(N - 10);
    int i = n;
    while (i > 0)
    {
        int minn = i + 1;
        while (!vis[minn]) minn++;
        int maxn = minn - i;
        for (int j = i; j >= maxn; j--) ans[j] = minn - j;
        i = maxn - 1;
    }
    for (int i = 1; i <= n; i++) std::cout << ans[i] << " ";
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