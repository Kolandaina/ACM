#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    int o = 0, j = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            o += x;
        else
            j += x;
    }
    if (o > j)
        cout << " YES" << endl;
    else
        cout << " NO" << endl;
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