#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5050;
int a[N], b[N];
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
        cin >> b[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i] * b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = sum;
        dp[i + 1][i] = sum;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j - 1] - a[i] * b[i] - a[j] * b[j] + a[i] * b[j] + a[j] * b[i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
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