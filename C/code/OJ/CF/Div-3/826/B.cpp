#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    if (n == 3)
        cout << -1 << endl;
    else
    {
        if (n % 2 == 0)
        {
            for (int i = n; i > 0; i--)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = n / 2; i <= n; i++)
            {
                cout << i << " ";
            }
            for (int i = 1; i < n / 2; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
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