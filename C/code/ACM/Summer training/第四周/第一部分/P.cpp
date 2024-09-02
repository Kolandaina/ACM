#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool f[3001][3001];
int dp[3001][3001];
inline void slove()
{
    int h, w, n;
    cin >> h >> w >> n;
    int a, b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        f[a][b] = 1;
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[i][j] = 3005;
        }
    }
    int sum = 0;
    for (int i = h; i >= 1; i--)
    {
        for (int j = w; j >= 1; j--)
        {
            if (i == h || j == w)
                dp[i][j] = 1;
            if (i < h)
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            if (j < w)
                dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            if (i < h && j < w)
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + 1);
            if (f[i][j])
                dp[i][j] = 0;
            sum += dp[i][j];
        }
    }
    cout << sum << endl;
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