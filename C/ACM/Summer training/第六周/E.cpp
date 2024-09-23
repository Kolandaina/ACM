#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int n, m, p, tot, head[N], dis[N];
int t, s, d;
bool vis[N];
struct edge
{
    int next, to, dis;
} g[N];
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
void disjkstra()
{
    priority_queue<node> q;
    for (int i = 0; i <= n + 10; i++)
    {
        dis[i] = 0x3fffffff;
    }
    memset(vis, false, sizeof(vis));
    dis[0] = 0;
    node tt = {0, 0};
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
    while (cin >> t >> s >> d)
    {
        memset(g, 0, sizeof(g));
        tot = 0;
        memset(head, 0, sizeof(head));
        for (int i = 0; i < t; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            add(x, y, w), add(y, x, w);
            n = max(n, max(x, y));
        }
        for (int i = 0; i < s; i++)
        {
            int x;
            cin >> x;
            add(0, x, 0), add(x, 0, 0);
        }
        for (int i = 0; i < d; i++)
        {
            int x;
            cin >> x;
            add(n + 1, x, 0), add(x, n + 1, 0);
        }
        disjkstra();
        cout << dis[n + 1] << endl;
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