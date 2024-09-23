// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// const int N = 2e5 + 10;
// vector<vector<pair<int, int>>> g(N);
// int deep[N];
// int n;
// int dfs(int u, int pa, int i)
// {
//     int ans = 0;
//     for (auto &[v, j] : g[u])
//     {
//         if (v != pa)
//         {
//             if (j < i)
//                 ans = max(ans, dfs(v, u, j) + 1);
//             else
//                 ans = max(ans, dfs(v, u, j));
//         }
//     }
//     return ans;
// }
// inline void slove()
// {
//     cin >> n;
//     for (int i = 0; i <= n; i++)
//     {
//         g[i].clear();
//     }
//     for (int i = 1; i <= n - 1; ++i)
//     {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back({v, i});
//         g[v].push_back({u, i});
//     }
//     cout << dfs(1, 0, 0) + 1 << endl;
// }
// signed main()
// {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     int t = 1;
//     cin >> t;
//     while (t--)
//         slove();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
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