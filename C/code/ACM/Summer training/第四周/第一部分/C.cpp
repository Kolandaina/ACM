#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 110;
const int mod = 1e6 + 7;
int a[N];
int dp[N][N];
inline void slove()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= min(j, a[i]); k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
            }
        }
    }
    cout << dp[n][m] << endl;
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