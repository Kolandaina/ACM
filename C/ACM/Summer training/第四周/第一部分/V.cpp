#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2020;
const int mod = 19650827;
int a[N], dp[N][N][2];
inline void slove()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i][0] = 1;
    }
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1, j = i + len; j <= n; i++, j++)
        {
            if (a[i] < a[i + 1])
            {
                dp[i][j][0] += dp[i + 1][j][0];
            }
            if (a[i] < a[j])
            {
                dp[i][j][0] += dp[i + 1][j][1];
            }
            if (a[j] > a[i])
            {
                dp[i][j][1] += dp[i][j - 1][0];
            }
            if (a[j] > a[j - 1])
            {
                dp[i][j][1] += dp[i][j - 1][1];
            }
            dp[i][j][0] %= mod;
            dp[i][j][1] %= mod;
        }
    }
    cout << (dp[1][n][0] + dp[1][n][1]) % mod << endl;
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