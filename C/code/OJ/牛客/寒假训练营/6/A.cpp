#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int l, r;
    std::cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (i == 30 || i == 42 || i == 66 || i == 78 || i == 70)
        {
            std::cout << i << " ";
            return;
        }
    }
    std::cout << -1 << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}