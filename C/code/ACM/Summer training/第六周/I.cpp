#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1010;
int n;
int f[N][N], dis[N];
int ans[N], vis[N];
void disjkstra()
{
    for (int i = 0; i < n; i++)
    {
        ans[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int t = 0, minn = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (minn > dis[j] && !vis[j])
            {
                minn = dis[j];
                t = j;
            }
        }
        vis[t] = true;
        for (int j = 0; j < n; j++)
        {
            if (f[t][j] != -1 && vis[j])
            {
                if (dis[f[t][j]] > dis[t] + dis[j])
                {
                    dis[f[t][j]] = dis[t] + dis[j];
                    ans[f[t][j]] = ans[t] * ans[j];
                }
                else if (dis[f[t][j]] == dis[t] + dis[j])
                {
                    ans[f[t][j]] += ans[t] * ans[j];
                }
            }
        }
    }
}
inline void slove()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dis[i];
    }
    memset(f, -1, sizeof(f));
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        f[a][b] = c;
        f[b][a] = c;
    }
    disjkstra();
    cout << dis[0] << " " << ans[0] << endl;
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