#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n, k, ans = 0;
    std::cin >> n >> k;
    std::vector<int> a(n + 1), sum(n + 1);
    std::map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    mp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = sum[i] % k;
        if (mp[cnt])
        {
            ans += mp[cnt];
            mp.clear();
        }
        mp[cnt]++;
    }
    std::cout << ans << endl;
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