#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k, s, t;
int dis[N];
vector<vector<pair<int, int>>> g(N);
bool vis[N];
struct node
{
    int dis, pos;
    bool operator<(const node &other) const
    {
        return other.dis < dis;
    }
};
void disjkstra()
{
    std::priority_queue<node> q;
    for (int i = 0; i < N; i++)
        dis[i] = 1e15;
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        node t = q.top();
        q.pop();
        if (vis[t.pos])
            continue;
        vis[t.pos] = true;
        for (auto e : g[t.pos])
        {
            if (dis[e.first] > dis[t.pos] + e.second)
            {
                dis[e.first] = dis[t.pos] + e.second;
                if (!vis[e.first])
                    q.push({dis[e.first], e.first});
            }
        }
    }
}
inline void slove()
{
    cin >> n >> m >> s >> t;
    k = 1;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        for (int j = 1; j <= k; j++)
        {
            g[x + (j - 1) * n].push_back({y + j * n, 0});
            g[x + j * n].push_back({y + j * n, w});
        }
    }
    for (int i = 1; i <= k; i++)
    {
        g[t + (i - 1) * n].push_back({t + i * n, 0});
    }
    disjkstra();

    if (dis[t + k * n] == 1e15)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dis[t + k * n] << endl;
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