#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int w, h, x1, y1, x2, y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2;
    int w2, h2;
    cin >> w2 >> h2;
    int w1 = abs(x1 - x2), h1 = abs(y1 - y2);
    if (w1 + w2 > w && h1 + h2 > h)
    {
        cout << -1 << endl;
        return;
    }
    int ans = INT_MAX;
    int down_y = h2 - y1, up_y = y2 + h2 - h;
    int down_x = w2 - x1, up_x = x2 + w2 - w;
    if (down_y <= 0 || up_y <= 0 || down_x <= 0 || up_x <= 0)
    {
        cout << 0 << endl;
        return;
    }
    if (h2 + h1 <= h)
        ans = min(ans, min(up_y, down_y));
    if (w2 + w1 <= w)
        ans = min(ans, min(down_x, up_x));
    cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}