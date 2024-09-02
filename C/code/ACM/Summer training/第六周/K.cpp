#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int n, m, k, s, p, Q;
vector<vector<int>> g(N); /* NOLINT */
vector<int> f;
int dis[N], deep[N], diss[N];
bool vis[N], bis[N];
struct node
{
    int dis, pos;
    bool operator<(const node &other) const
    {
        return other.dis < dis;
    }
};
void bfs(int tt)
{
    queue<int> qu;
    memset(deep, 0, sizeof(deep));
    qu.push(tt);
    deep[tt] = 1;
    while (!qu.empty())
    {
        int t = qu.front();
        qu.pop();
        for (auto e : g[t])
        {
            if (deep[e])
                continue;
            deep[e] = deep[t] + 1;
            if (deep[e] - 1 <= s)
            {
                diss[e] = Q;
                qu.push(e);
            }
        }
    }
}
void disjkstra()
{
    priority_queue<node> q;
    for (int i = 0; i <= n; i++)
        dis[i] = 1e15;
    memset(vis, false, sizeof(vis));
    dis[1] = 0;
    q.push({0, 1});
    while (!q.empty())
    {
        node t = q.top();
        q.pop();
        if (vis[t.pos] || bis[t.pos])
            continue;
        vis[t.pos] = true;
        for (auto e : g[t.pos])
        {
            if (dis[e] > dis[t.pos] + diss[e])
            {
                dis[e] = dis[t.pos] + diss[e];
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
    cin >> n >> m >> k >> s >> p >> Q;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        f.push_back(x);
        bis[x] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i <= n; i++)
        diss[i] = p;
    for (auto e : f)
        bfs(e);
    diss[1] = 0, diss[n] = 0;
    disjkstra();
    cout << dis[n] << endl;
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