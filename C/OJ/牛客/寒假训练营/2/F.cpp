#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;

inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(N + 1);
    std::vector<int> pos[n + 1];
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        pos[a[i]].push_back(i);
    }
    int maxn = n, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pos[i].size())
        {
            maxn = std::min(maxn, pos[i].back());
        }
    }
    int now = maxn, pre = n;
    while (pre >= 1)
    {
        ans++;
        maxn = now;
        for (int i = pre; i >= now; i--)
        {
            pos[a[i]].pop_back();
            if (pos[a[i]].size())
            {
                maxn = std::min(maxn, pos[a[i]].back());
            }
        }
        pre = now - 1;
        now = maxn;
    }
    std::cout << ans << endl;
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