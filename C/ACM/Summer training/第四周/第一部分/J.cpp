#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1005;
const int M = 40005;
const int mod = 998244353;
int a[N];
int dp[N][M];
inline void slove()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int d;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + i) % mod;
        for (int j = i - 1; j >= 1; j--)
        {
            d = a[i] - a[j];
            ans = (ans + dp[j][d + N]) % mod;
            dp[i][N + d] = (dp[i][d + N] + dp[j][d + N] + 1) % mod;
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