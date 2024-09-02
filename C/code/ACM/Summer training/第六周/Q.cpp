#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e5 + 10;
int dis[N], head[N], n, s, m, tot;
int a[N], sum, ans = INT_MAX;
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
    g[tot].dis = w;
}
void disjkstra(int s)
{
    priority_queue<node> q;
    for (int i = 0; i <= n; i++)
    {
        dis[i] = INT_MAX;
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
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
    }
    disjkstra(s);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
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