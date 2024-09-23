#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    int x = n;
    int ans1 = 0, ans2 = 0;
    while (x > 1)
    {
        if (x % 2 == 0)
        {
            x = x / 2;
            ans1++;
        }
        else
            break;
    }
    while (x > 1)
    {
        if (x % 3 == 0)
            x = x / 3;
        else
            break;
    }
    if (x != 1)
    {
        cout << -1 << endl;
        return;
    }
    x = n;
    while (x > 1)
    {
        if (x % 3 == 0)
        {
            x = x / 3;
            ans2++;
        }
        else
            break;
    }
    if (n == 1)
        cout << 0 << endl;
    else if (ans1 > ans2)
        cout << -1 << endl;
    else
        cout << ans2 + abs(ans1 - ans2) << endl;
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