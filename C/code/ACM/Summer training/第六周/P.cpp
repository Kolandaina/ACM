#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
#define endl "\n"
const int N = 110;
int dp[N][N];
int n, m;
inline void slove()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = 0x3fffffffff;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        dp[x][y] = dp[y][x] = w;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
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