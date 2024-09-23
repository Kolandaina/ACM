#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int dp[100][100];
inline void slove()
{
    string s;
    cin >> s;
    int n = s.length();
    memset(dp, 0x3f3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int l = i, r = i + len - 1;
            if (s[l - 1] == s[r - 1])
            {
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
                continue;
            }
            for (int k = l; k <= r; k++)
            {
                dp[l][r] = min(dp[l][k] + dp[k + 1][r], dp[l][r]);
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