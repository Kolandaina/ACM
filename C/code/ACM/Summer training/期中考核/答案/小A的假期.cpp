#include <bits/stdc++.h>

#define int long long

int x, y, l = 0, r = 0, n, m, cnt = 0;
int next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int mp[507][507], h[507][507], vis[507][507];

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> mp[i][j];
            if (mp[i][j] == 1)
            {
                cnt++;
                x = i, y = j;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> h[i][j];
            r = std::max(r, h[i][j]);
        }
    }

    auto check = [&](int H) -> bool
    {
        memset(vis, 0, sizeof(vis));
        std::queue<std::pair<int, int>> q;
        int res = 0;
        q.push({x, y});
        vis[x][y] = 1;

        while (!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if (mp[a][b] == 1)
                res++;
            if (res == cnt)
                break;
            for (int i = 0; i < 4; i++)
            {
                int aa = a + next[i][0];
                int bb = b + next[i][1];
                if (aa < 1 || aa > n || bb < 1 || bb > m || vis[aa][bb] == 1)
                    continue;
                if (std::fabs(h[aa][bb] - h[a][b]) <= H)
                {
                    vis[aa][bb] = 1;
                    q.push({aa, bb});
                }
            }
        }

        return res == cnt;
    };

    int res;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid - 1, res = mid;
        else
            l = mid + 1;
    }

    std::cout << res;

    return 0;
}
