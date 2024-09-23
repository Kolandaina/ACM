#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[2005][2005];
int arr[2005];
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 2003; i++)
    {
        dp[i][0] = 0;
    }

    int ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m && i >= j; j++)
        {
            if (i == j)
                dp[i][j] = dp[i - 1][j - 1] + j * arr[i];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + j * arr[i]);
            if (j == m)
                ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}