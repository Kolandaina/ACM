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
int n, s, m, tot, dis[N], pos[N], ans[N];
bool vis[N];
struct node
{
    int dis, first;
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
        dis[i] = 1e15;
    }
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        node t = q.top();
        q.pop();
        if (vis[t.first])
            continue;
        vis[t.first] = true;
        for (auto e : g[t.first])
        {
            if (dis[e.first] > dis[t.first] + e.second)
            {
                dis[e.first] = dis[t.first] + e.second;
                pos[e.first] = t.first;
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
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    disjkstra(1);
    int o = 0, flag = 1;
    for (int i = n; i; i = pos[i])
    {
        ans[++o] = i;
        if (i == 1)
            flag = 0;
    }
    if (flag)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = o; i >= 1; i--)
        {
            cout << ans[i] << " ";
        }
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