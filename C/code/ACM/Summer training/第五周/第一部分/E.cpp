#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
vector<vector<int>> g(N);
int n, m;
int vis[N];
void dfs(int x)
{
    cout << x << " ";
    vis[x] = 1;
    for (auto e : g[x])
    {
        if (!vis[e])
            dfs(e);
    }
}
void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto e : g[x])
        {
            if (!vis[e])
            {
                vis[e] = 1;
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
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    dfs(1);
    cout << endl;
    memset(vis, 0, sizeof(vis));
    bfs();
    cout << endl;
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