#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int a[N][N], dp[N][N], ans;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(dp[n][i], ans);
    }
    cout << ans << endl;
    return 0;
}