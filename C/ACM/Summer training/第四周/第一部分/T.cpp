#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e3;
int a[N];
int dp1[N][N], dp2[N][N], s[N][N];
inline void slove()
{
    memset(dp1, 0x3f, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
        dp1[i][i] = 0;
        dp2[i][i] = 0;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        dp1[i][i] = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i == j)
            {
                s[i][j] = a[i];
            }
            else
            {
                s[j][i] = s[j][i - 1] + a[i];
            }
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            for (int k = j; k < j + i; k++)
            {
                int w1 = dp1[j][k] + dp1[k + 1][j + i] + s[j][i + j];
                int w2 = dp2[j][k] + dp2[k + 1][j + i] + s[j][i + j];
                if (w1 < dp1[j][j + i])
                {
                    dp1[j][j + i] = w1;
                }
                if (w2 > dp2[j][i + j])
                {
                    dp2[j][i + j] = w2;
                }
            }
        }
    }
    int ans1 = INT_MAX, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp1[i][i + n - 1] < ans1)
        {
            ans1 = dp1[i][i + n - 1];
        }
        if (dp2[i][i + n - 1] > ans2)
        {
            ans2 = dp2[i][i + n - 1];
        }
    }
    cout << ans1 << endl
         << ans2 << endl;
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