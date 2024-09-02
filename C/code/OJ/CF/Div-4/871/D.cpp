#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout << "YES" << endl;
        return;
    }
    while (n % 3 == 0)
    {
        n /= 3;
        if (n % m != 0)
            n *= 2;
        if (n == m)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO" << endl;
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