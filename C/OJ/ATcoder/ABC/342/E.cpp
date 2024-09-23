#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
inline void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::array<int, 5>>> g(n);
    for (int i = 0; i < m; i++) {
        int l, d, k, c, a, b;
        std::cin >> l >> d >> k >> c >> a >> b;
        a--, b--;
        g[b].push_back({a, l, d, k, c});
    }
    std::vector<int> dis(n, -1);
    std::priority_queue<std::pair<int, int>> q;
    q.emplace(4E18, n - 1);
    while (!q.empty()) {
        auto [ds, x] = q.top();
        q.pop();
        if (dis[x] != -1) {
            continue;
        }
        dis[x] = ds;
        for (auto [y, l, d, k, c] : g[x]) {
            int m = ds - c;
            if (m >= l) {
                m = l + std::min((m - l) / d, 1LL * (k - 1)) * d;
                q.emplace(m, y);
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (dis[i] == -1) {
            std::cout << "Unreachable" << endl;
        } else {
            std::cout << dis[i] << endl;
        }
    }
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
