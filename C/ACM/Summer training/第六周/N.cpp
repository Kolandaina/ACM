#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
vector<vector<int>> g(N); /* NOLINT */
int n, m, s, r, dis[N], diss[N], ans;
bool vis[N];
struct node
{
    int dis, pos;
    bool operator<(const node &other) const
    {
        return other.dis < dis;
    }
};
void disjkstra(int ss)
{
    priority_queue<node> q;
    for (int i = 0; i <= n; i++)
        dis[i] = 1e15;
    memset(vis, false, sizeof(vis));
    dis[ss] = 0;
    q.push({0, ss});
    while (!q.empty())
    {
        node t = q.top();
        q.pop();
        if (vis[t.pos])
            continue;
        vis[t.pos] = true;
        for (auto e : g[t.pos])
        {
            if (dis[e] > dis[t.pos] + 1)
            {
                dis[e] = dis[t.pos] + 1;
                if (!vis[e])
                {
                    q.push({dis[e], e});
                }
            }
        }
    }
}
inline void slove()
{
    cin >> n >> m >> s >> r;
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    disjkstra(s);
    for (int i = 1; i <= n; i++)
        diss[i] = dis[i];
    disjkstra(r);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (diss[i] + dis[j] + 1 >= diss[r] && diss[j] + dis[i] + 1 >= diss[r])
            {
                ans++;
            }
        }
    }
    cout << ans - m << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        slove();
    return 0;
}