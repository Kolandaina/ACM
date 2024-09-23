#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int a[10][10];
int dp[10][10][10][10];
inline void slove()
{
    int n;
    cin >> n;
    int x, y, s;
    while (cin >> x >> y >> s && y)
    {
        a[x][y] = s;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int l = 1; l <= n; l++)
            {
                for (int k = 1; k <= n; k++)
                {
                    dp[i][j][l][k] = max(max(dp[i - 1][j][l - 1][k], dp[i][j - 1][l][k - 1]),
                                         max(dp[i - 1][j][l][k - 1], dp[i][j - 1][l - 1][k]));
                    dp[i][j][l][k] += a[i][j];
                    if (i != 1 && j != k)
                    {
                        dp[i][j][l][k] += a[l][k];
                    }
                }
            }
        }
    }
    cout << dp[n][n][n][n] << endl;
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