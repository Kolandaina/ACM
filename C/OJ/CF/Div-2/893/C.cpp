#include <bits/stdc++.h>
#define endl "\n"
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> vis(n + 1, 1);
    for (int i = 2; i <= n / 2; i++)
    {
        if (vis[i])
        {
            vis[i] = 0;
            std::cout << i << " ";
            for (int j = i * 2; j <= n && vis[j]; j = j * 2)
            {
                std::cout << j << " ";
                vis[j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            std::cout << i << " ";
        }
    }
    std::cout << endl;
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