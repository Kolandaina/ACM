#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30;
int n, m, p, q;
bool s[N][N];
int f[N][N];
const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
signed main()
{
    cin >> n >> m >> p >> q;
    n += 2;
    m += 2;
    p += 2;
    q += 2;
    f[2][1] = 1;
    s[p][q] = 1;
    for (int i = 1; i <= 8; i++)
    {
        s[p + fx[i]][q + fy[i]] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (s[i][j])
            {
                continue;
            }
            f[i][j] += f[i - 1][j] + f[i][j - 1];
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
