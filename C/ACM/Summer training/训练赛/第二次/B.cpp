#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, k, m;
    cin >> n >> m;
    if (n < m)
        swap(n, m);
    if (n && m)
    {
        if (n > m)
        {
            int sum = 0;
            k = n - m;
            if (2 * k <= n && k <= m)
            {
                n -= 2 * k;
                m -= k;
                sum += k;
                sum += ((n + m) / 3);
                cout << sum << endl;
            }
            else
            {
                k = min(n, k);
                k = min(m, k);
                cout << k << endl;
            }
        }
        else
        {
            cout << (n + m) / 3 << endl;
        }
    }
    else
        cout << 0 << endl;
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