#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= 10 || b + c >= 10 || a + c >= 10)
    {
        cout << "YES" << endl;
    }
    else
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