#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
struct node
{
    int first, second;
};
std::vector<node> g[N];
std::vector<int> dis(N);
std::vector<bool> vis(N);
void bfs(int s)
{
    for (int i = 1; i <= n; i++) vis[i] = 0, dis[i] = INF;
    std::queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto e : g[t])
        {
            int v = e.first, w = e.second;
            if (dis[v] > dis[t] + w)
            {
                dis[v] = dis[t] + w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
inline void slove()
{
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        char ch;
        std::cin >> x >> y >> w >> ch;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    bfs(1);
    int maxn = 0, pos = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxn)
        {
            maxn = dis[i];
            pos = i;
        }
    }
    bfs(pos);
    maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxn)
        {
            maxn = dis[i];
        }
    }
    std::cout << maxn << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}