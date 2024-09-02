#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1010;
int n, m;
double g[N][N], dis[N];
bool vis[N];
double dijkstra(int s, int r)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = g[s][i];
    }
    dis[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = s;
        double max = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] > max)
            {
                t = j;
                max = dis[j];
            }
        }
        vis[t] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] < dis[t] * g[t][j])
            {
                dis[j] = dis[t] * g[t][j];
            }
        }
        if (t == r)
            return dis[t];
    }
    return 0;
}
inline void slove()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%lf", &g[i][j]);
            }
        }
        cin >> m;
        while (m--)
        {

            memset(vis, false, sizeof(vis));
            int s, t;
            cin >> s >> t;
            double ans = dijkstra(s, t);
            if (ans)
            {
                printf("%.3f\n", ans);
            }
            else
            {
                printf("What a pity!\n");
            }
        }
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