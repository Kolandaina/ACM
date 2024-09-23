#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
vector<vector<int>> g(N);
bool vis[N], dis[N];
int n, m, s, r;
int ans[N];
void bfs1()
{
    queue<int> q;
    q.push(r);
    vis[r] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto e : g[t])
        {
            if (!vis[e])
            {
                vis[e] = true;
                q.push(e);
            }
        }
    }
}
void bfs2()
{
    queue<int> q;
    q.push(r);
    vis[r] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto e : g[t])
        {
            if (dis[e])
            {
                dis[e] = false;
                ans[e] = ans[t] + 1;
                q.push(e);
            }
        }
    }
}
inline void slove()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x != y)
            g[y].push_back(x);
    }
    cin >> s >> r;
    bfs1();
    memcpy(dis, vis, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            for (auto e : g[i])
            {
                if (dis[e])
                {
                    dis[e] = false;
                }
            }
        }
    }
    bfs2();
    if (ans[s] == 0)
        cout << -1 << endl;
    else
        cout << ans[s] << endl;
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