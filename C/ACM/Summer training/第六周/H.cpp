#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
#define int long long
#define endl "\n"
const int M = 1e5;
int n, m, b, tot, dis[M], head[M], a[M];
int l, r;
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
void disjkstra(int maxn)
{
    priority_queue<node> q;
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 0x3fffffff;
    }
    memset(vis, false, sizeof(vis));
    dis[1] = 0;
    node tt = {0, 1};
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
            if (a[e] > maxn)
                continue;
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
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    l = max(a[1], a[n]);
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w), add(y, x, w);
    }
    while (l < r)
    {
        int mid = (l + r) >> 1;
        disjkstra(mid);
        if (dis[n] > b)
            l = mid + 1;
        else
            r = mid;
    }
    disjkstra(l);
    if (dis[n] > b)
        cout << "AFK" << endl;
    else
        cout << l << endl;
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