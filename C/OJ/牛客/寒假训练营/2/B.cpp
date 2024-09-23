#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 1000;
inline void slove()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    int mp[N + 1][N + 1] = {0};
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        std::cin >> x >> y;
        mp[x][y] = 1;
        ans += 4;
        ans -= mp[x + 1][y] + mp[x - 1][y] + mp[x][y + 1] + mp[x][y - 1];
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
    while (t--)
        slove();
    return 0;
}