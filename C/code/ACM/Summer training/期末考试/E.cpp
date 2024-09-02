#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e7;
int n, m, a[10000000];
inline void slove()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                a[i]++;
                if (j != i / j)
                    a[i]++;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (a[x] % 2 == 0)
        {
            cout << "F" << endl;
        }
        else
        {
            cout << "T" << endl;
        }
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}