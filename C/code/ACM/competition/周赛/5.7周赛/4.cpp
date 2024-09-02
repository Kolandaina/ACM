#include <bits/stdc++.h>
#define int long long
std::map<std::pair<int, int>, int> mp;
std::map<int, int> vis;
int n, m;
int dfs(int u)
{
    vis[u] = -1;
    for (int i = 1; i <= n; i++)
    {
        if (mp[{u, i}])
        {
            if (vis[i] == -1)
                return 0;
            if (!vis[i] && !dfs(i))
                return 0;
        }
    }
    vis[u] = 1;
    return 1;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    while (m--)
    {
        int x, y;
        std::cin >> x >> y;
        mp[{y, x}] = 1;
    }
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (!dfs(i))
            {
                f = 0;
                break;
            }
        }
    }
    if (f == 1)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
