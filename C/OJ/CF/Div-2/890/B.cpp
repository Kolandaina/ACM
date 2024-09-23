#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cin >> n;
        cout << "NO\n";
    }
    else
    {
        int a, one = 0, count = 0, k = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a == 1)
                one++;
            else
            {
                count += a;
                k++;
            }
        }
        if ((count - one - k) >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
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