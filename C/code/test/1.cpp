#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
inline void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    std::vector<int> size(n + 1);
    std::function<void(int, int)> dfs = [&](int u, int fa) {
        size[u] = 1;
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            size[u] += size[v];
        }
    };
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (size[i] == 1)ans++;
    }
    if (n == 2)std::cout << 2 << endl;
    else std::cout << ans << endl;
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) solve();
    return 0;
}