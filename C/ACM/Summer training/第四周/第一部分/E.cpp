#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 30;
int a[N], b[N];
int f[N][N];
int dp[N];
int ans = 0, pos = 0;
void dfs(int x)
{
    if (b[x])
    {
        dfs(b[x]);
    }
    cout << x << " ";
}
inline void slove()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1 + i; j <= n; j++)
        {
            cin >> f[i][j];
        }
    }
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = a[i];
        for (int j = i - 1; j > 0; j--)
        {
            if (f[j][i] && dp[i] < dp[j] + a[i])
            {
                dp[i] = dp[j] + a[i];
                b[i] = j;
            }
        }
        if (ans < dp[i])
        {
            ans = dp[i];
            pos = i;
        }
    }
    dfs(pos);
    cout << "\n"
         << ans << endl;
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