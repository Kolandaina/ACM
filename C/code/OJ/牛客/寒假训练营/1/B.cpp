#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    std::cin >> n;
    std::map<int, int> p[5];
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        p[x][y]++;
        if (y < 0)
            l = std::max(l, p[x][y] + p[3 - x][y] + p[3 - x][y - 1] + p[3 - x][y + 1]);
        if (y > 0)
            r = std::max(r, p[x][y] + p[3 - x][y] + p[3 - x][y - 1] + p[3 - x][y + 1]);
    }
    l = std::min(l, 2ll);
    r = std::min(r, 2ll);
    int ans = 4 - l - r;
    int res = 3 - std::max(p[1][-1], l / 2) - std::max(p[1][1], r / 2) - p[2][0];
    std::cout << std::min(res, ans) << endl;
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