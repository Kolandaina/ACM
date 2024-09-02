#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 1e5 + 10;
int x[N], y[N], z[N];
inline void slove()
{
    int n;
    std::cin >> n;
    bool flag = 0;
    for (int i = 1; i <= n; i++) std::cin >> x[i] >> y[i] >> z[i];
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                int a[4];
                a[1] = i, a[2] = j, a[3] = k;
                bool flag2 = 1;
                for (int p = 1; p <= n; p++)
                {
                    if (z[p] == 0)
                    {
                        if (a[x[p]] < a[y[p]]) flag2 = 0;
                    }
                    else
                    {
                        if (a[x[p]] >= a[y[p]]) flag2 = 0;
                    }
                }
                if (flag2) flag = 1;
            }
        }

    std::cout << (flag ? "YES" : "NO") << endl;
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