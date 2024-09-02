#include <functional>
#include <iostream>
#include <vector>

#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    std::vector<std::vector<int>> g(N);
    std::vector<int> num(N);
    int ans, pos, n;
    std::cin >> n;
    pos = 1, ans = n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    std::function<void(int, int)> dfs = [&](int u, int fa) {
        num[u] = 1;
        int temp = 0;
        for (auto v : g[u])
        {
            if (v == fa) continue;
            dfs(v, u);
            num[u] += num[v];
            temp = std::max(temp, num[v]);
        }
        temp = std::max(temp, n - num[u]);
        if (temp < ans)
        {
            ans = temp;
            pos = u;
        }
    };
    dfs(1, 0);
    std::cout << pos << " " << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) slove();
    return 0;
}