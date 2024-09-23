#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e5 + 10;
vector<vector<pair<int, int>>> g(N);
int n, s, m, tot, dis[N];
bool vis[N];
struct node
{
    int dis, pos;
    bool operator<(const node &x) const
    {
        return x.dis < dis;
    }
};
void disjkstra(int s)
{
    priority_queue<node> q;
    for (int i = 0; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
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
                {
                    q.push({dis[e.first], e.first});
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
        g[x].push_back({y, w});
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