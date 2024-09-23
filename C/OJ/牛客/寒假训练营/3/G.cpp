#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
inline void slove()
{
    int n;
    std::cin >> n;
    int x[5], y[5], z[5];
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> x[i] >> y[i] >> z[i];
        if (x[i] == y[i] && z[i] == 1) flag = 1;
        if (i == 2)
        {
            if ((x[i] + y[i]) == (x[1] + y[1]))
            {
                if (x[1] == x[2] && z[1] != z[2]) flag = 1;
                if (x[1] != x[2] && z[1] == z[2] && z[1] == 1) flag = 1;
            }
        }
    }
    std::cout << (flag ? "NO" : "YES") << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) slove();
    return 0;
}