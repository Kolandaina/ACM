#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    while (a != b)
    {
        if (a < b)
            swap(a, b);
        if (a > b)
        {
            if (a % b == 0)
            {
                ans += a / b - 1;
                break;
            }
            else
                ans += a / b, a %= b;
        }
    }
    cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}