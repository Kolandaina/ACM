#include <iostream>
#include <queue>
#include <vector>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
std::vector<std::vector<int>> g(N);
std::vector<int> dis(N);
std::vector<bool> vis(N);
std::vector<int> p(N);
std::vector<int> a(N);
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int dfs(int s)
{
    vis[s] = true;
    int father = s;
    for (auto e : g[s])
    {
        if (!vis[e])
        {
            vis[e] = true;
            dis[e] = dis[s] + 1;
            int t = dfs(e);
            if (dis[t] > dis[father]) father = t;
        }
    }
    return father;
}
inline void slove()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        p[i] = i;
    }
    std::queue<std::pair<int, int>> q;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        x = find(x), y = find(y);

        if (a[x] == a[y] && x != y) p[x] = y;
        else if (a[x] != a[y]) q.push({x, y});
    }
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        x = find(x), y = find(y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int pos = dfs(find(1));
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 0;
        vis[i] = false;
    }
    int w = dfs(pos);
    std::cout << (dis[w] - dis[pos] + 1) / 2 << endl;
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