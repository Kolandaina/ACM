#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 5010;
const int INF = 0x3f3f3f3f;
inline void slove()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n + 1), b(n + 1);
    std::vector<bool> vis(N + 1, 0);
    std::vector<int> dis(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        dis[i] = INF;
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a[i] >> b[i];
    }
    std::priority_queue<std::pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        auto temp = q.top();
        q.pop();
        temp.first = -temp.first;
        if (vis[temp.second])
            continue;
        vis[temp.second] = 1;
        for (int i = 1; i <= m; i++)
        {
            int j = ((temp.second + a[i]) % n);
            if (vis[j])
                continue;
            if (dis[j] > temp.first + b[i])
            {
                dis[j] = temp.first + b[i];
                q.push({-dis[j], j});
            }
        }
    }
    if (dis[n - k] == INF)
    {
        std::cout << -1 << endl;
    }
    else
    {
        std::cout << dis[n - k] << endl;
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        slove();
    return 0;
}