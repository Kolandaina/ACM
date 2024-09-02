#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1000;
int n;
int dis[N][N], res[N], ans[N];
bool vis[N];
inline void slove()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dis[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> res[i];
    }
    for (int r = n; r > 0; r--)
    {
        int k = res[r];
        vis[k] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    if (vis[i] && vis[j])
                    {
                        ans[r] += dis[i][j];
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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