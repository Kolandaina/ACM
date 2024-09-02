#include <bits/stdc++.h>

#define int long long

struct node
{
    int a, b, c, x, y;
} e[10];

int n, t, p;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n >> t >> p;

    for (int i = 0; i < n; i++)
    {
        std::cin >> e[i].a >> e[i].b >> e[i].c >> e[i].x >> e[i].y;
    }

    int res = 0;
    std::vector<int> vis(10);
    std::function<void(int, int, int)> dfs = [&](int cnt, int ti, int sum)
    {
        if (cnt > n || ti > t)
        {
            return;
        }
        res = std::max(res, sum);

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 1)
                continue;
            vis[i] = 1;
            dfs(cnt + 1, ti + e[i].x, sum + std::max(e[i].c, e[i].a - (ti + e[i].x) * e[i].b - e[i].y * p));
            vis[i] = 0;
        }
    };

    dfs(0, 0, 0);

    std::cout << res;

    return 0;
}
