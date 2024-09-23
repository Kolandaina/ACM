#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int g[110][110], f[110][110];
int n, m;
inline void slove()
{
    cin >> n >> m;
    memset(g, -1, sizeof(g));
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x][y] = w, g[y][x] = w;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (g[i][k] != -1 && g[k][j] != -1)
                {
                    if (g[i][j] == -1 || g[i][j] > g[k][j] + g[i][k])
                    {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= n; y++)
                {
                    f[x][y] = g[x][y];
                }
            }
            f[i][j] = f[j][i] = 0;
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= n; y++)
                {
                    if (f[x][y] == -1 || f[x][y] > f[x][i] + f[i][y])
                    {
                        f[x][y] = f[x][i] + f[i][y];
                    }
                }
            }

            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= n; y++)
                {
                    if (f[x][y] == -1 || f[x][y] > f[x][j] + f[j][y])
                    {
                        f[x][y] = f[x][j] + f[j][y]; // Floyd
                    }
                }
            }
            int res = 0;
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y < x; y++)
                {
                    res += f[x][y];
                }
            }
            // cout << res << " ";
            ans = min(res, ans);
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