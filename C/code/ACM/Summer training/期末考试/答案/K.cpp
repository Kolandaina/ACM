#include <bits/stdc++.h>

using namespace std;
int dp[3103][3013];
char matrix[3010][3010];

signed main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                if (matrix[i][0] == '1')
                {
                    dp[i][0] = 1;
                    ans = max(ans, dp[i][0]);
                }
                else
                    dp[i][0] = 0;
            }
            else if (i == 0)
            {
                if (matrix[i][j] == '1')
                {
                    dp[0][j] = 1;
                    ans = max(ans, dp[0][j]);
                }
                else
                    dp[0][j] = 0;
            }
            else
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    ans = max(dp[i][j], ans);
                }
                else
                    dp[i][j] = 0;
            }
        }
    }
    cout << ans * ans << '\n';
}