#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5;
int dis[N], head[N], n, p, m, tot;
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
    for (int i = 1; i <= p; i++)
    {
        dis[i] = 0x3ffffff;
    }
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    q.push((node){0, s});
    while (!q.empty())
    {
        node t = q.top();
        q.pop();
        if (vis[t.pos])
            continue;
        vis[t.pos] = 1;
        for (int i = head[t.pos]; i; i = g[i].next)
        {
            int e = g[i].to;
            if (dis[e] > dis[t.pos] + g[i].dis)
            {
                dis[e] = dis[t.pos] + g[i].dis;
                if (!vis[e])
                {
                    q.push((node){dis[e], e});
                }
            }
        }
    }
}
inline void slove()
{
    cin >> n >> p >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w), add(y, x, w);
    }
    for (int i = 1; i <= p; i++)
    {
        disjkstra(i);
        sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += dis[a[j]];
        }
        ans = min(ans, sum);
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