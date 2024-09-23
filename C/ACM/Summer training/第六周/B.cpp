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
    while (cin >> n >> m)
    {
        memset(dp, 0, sizeof(dp));
        int flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = 0x3ffffff;
            }
        }
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            dp[x][y] = dp[y][x] = 1;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] > 7)
                {
                    flag = false;
                }
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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