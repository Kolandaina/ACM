#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5 + 7;
int n, m, s, x, y, w, t;
struct edge
{
    int t, n;
    ll w;
} g[N * 3];
ll dis[N], dis2[N];
int vis[N];
ll inf = 1e17;
struct node
{
    int u;
    ll d;
    bool operator<(const node &a) const
    {
        return d > a.d;
    }
};
int cnt = 1;
int head[N];
void add(int f, int t, ll w)
{
    g[cnt].n = head[f];
    g[cnt].t = t;
    g[cnt].w = w;
    head[f] = cnt++;
}
void init()
{
    for (int i = 0; i <= N - 1; i++)
        dis[i] = inf, vis[i] = 0;
}
void dij(int s)
{
    priority_queue<node, vector<node>> pq;
    pq.push((node){s, 0});
    dis[s] = 0;
    while (!pq.empty())
    {
        node tmp = pq.top();
        pq.pop();
        int u = tmp.u;
        if (vis[u])
            continue;
        vis[u]++;
        for (int i = head[u]; i; i = g[i].n)
        {
            int to = g[i].t;
            if (dis[to] > dis[u] + g[i].w)
            {
                dis[to] = min(dis[to], dis[u] + g[i].w);
                if (!vis[to])
                {
                    pq.push((node){to, dis[to]});
                }
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    vector<pair<pair<int, int>, ll>> d;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        add(x, y, w); // add(y,x,w);
        d.push_back(make_pair(make_pair(x, y), w));
    }
    init();
    dij(s);
    if (dis[t] == inf)
    {
        cout << -1;
        return 0;
    }
    ll ans = inf;
    for (int i = 1; i <= n; i++)
        dis2[i] = dis[i];
    ans = min(ans, dis[t]);
    memset(head, 0, sizeof head);
    cnt = 1;
    for (int i = 0; i < m; i++)
    {
        add(d[i].first.second, d[i].first.first, d[i].second); // add(y,x,w);
    }
    init();
    dij(t);
    if (dis[s] == inf)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        ans = min({ans, dis[d[i].first.second] + dis2[d[i].first.first]});
    }
    if (ans == inf)
        ans = -1;
    cout << ans;
}