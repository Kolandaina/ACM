#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int a[210];
int dp[210][210];
inline void slove()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    int maxn = 0;
    for (int i = 2; i < 2 * n; i++)
    {
        for (int j = i - 1; i - j < n && j >= 1; j--)
        {
            for (int k = j; k < i; k++)
            {
                dp[j][i] = max(dp[j][i], dp[j][k] + dp[k + 1][i] + a[j] * a[k + 1] * a[i + 1]);
                if (dp[j][i] > maxn)
                {
                    maxn = dp[j][i];
                }
            }
        }
    }
    cout << maxn << endl;
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