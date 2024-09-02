#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1000;
int n, m;
int g[N][N], dis[N];
bool vis[N];
int dijkstra()
{
    dis[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (t == -1 || dis[t] > dis[j]))
            {
                t = j;
            }
        }
        vis[t] = true;
        for (int j = 1; j <= n; j++)
        {
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        }
    }
    return dis[n];
}
inline void slove()
{
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        memset(g, 0x3f, sizeof(g));
        memset(vis, false, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a][b] = min(g[a][b], c);
            g[b][a] = min(g[b][a], c);
        }
        cout << dijkstra() << endl;
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