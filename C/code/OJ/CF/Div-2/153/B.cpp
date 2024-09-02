#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    if (m - a1 - ak * k <= 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int ans = m - a1 - ak * k;
        if (m - ak * k - k < a1)
        {
            cout << 1 << endl;
        }
        else
            cout << ans / k + ans % k << endl;
    }
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