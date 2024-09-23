#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1000;
int a[N];
int dp[N][N];
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
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i + 1] = 1 + (a[i] != a[i + 1]);
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; i + j - 1 <= n; j++)
        {
            int l = j, r = i + j - 1;
            if (a[l] == a[r])
            {
                dp[l][r] = dp[l + 1][r - 1];
            }
            for (int k = l; k < r; k++)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }
    cout << dp[1][n] << endl;
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