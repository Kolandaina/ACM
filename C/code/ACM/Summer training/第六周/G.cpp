#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
#define int long long
#define endl "\n"
const int M = 1e5;
int n, m, t, tot, dis[M], head[M];
bool vis[M];
struct edge
{
    int next, to, dis;
} g[M];
struct node
{
    int dis, pos;
    bool operator<(const node &x) const
    {
        return x.dis < dis;
    }
};
inline void add(int x, int y, int w)
{
    g[++tot].to = y;
    g[tot].next = head[x];
    head[x] = tot;
    if (g[tot].dis == 0)
        g[tot].dis = w;
    else
        g[tot].dis = min(g[tot].dis, w);
}
void disjkstra(int s)
{
    priority_queue<node> q;
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 0x3fffffff;
    }
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    node tt = {0, s};
    q.push(tt);
    while (!q.empty())
    {
        node t = q.top();
        q.pop();
        if (vis[t.pos])
            continue;
        vis[t.pos] = true;
        for (int i = head[t.pos]; i; i = g[i].next)
        {
            int e = g[i].to;
            if (dis[e] > dis[t.pos] + g[i].dis)
            {
                dis[e] = dis[t.pos] + g[i].dis;
                if (!vis[e])
                {
                    tt = {dis[e], e};
                    q.push(tt);
                }
            }
        }
    }
}
inline void slove()
{
    while (cin >> n >> m >> t)
    {
        memset(g, 0, sizeof(g));
        memset(head, 0, sizeof(head));
        tot = 0;
        for (int i = 0; i < m; i++)
        {
            int x, y, w;
            scanf("%lld%lld%lld", &x, &y, &w);
            add(y, x, w);
        }
        disjkstra(t);
        int k;
        cin >> k;
        int ans = 0x3fffffff;
        while (k--)
        {
            int x;
            cin >> x;
            ans = min(ans, dis[x]);
        }
        if (ans == 0x3fffffff)
            cout << -1 << endl;
        else
            cout << ans << endl;
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