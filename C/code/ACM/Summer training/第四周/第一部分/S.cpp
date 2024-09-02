#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e3;
int a[N];
int dp[N][N], s[N];
inline void slove()
{
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        dp[i][i] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            int k = i + j - 1;
            for (int l = j; l < k; l++)
            {
                dp[j][k] = min(dp[j][k], dp[j][l] + dp[l + 1][k] + s[k] - s[j - 1]);
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