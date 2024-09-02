#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E9;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> p(n), h(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);
    }

    std::vector dp(n, std::vector<i64>(n));
    i64 ans = 0;
    auto dfs = [&](auto &self, int x) -> void {
        if (adj[x].empty()) {
            dp[x][0] += inf;
            return;
        }
        i64 sum = 0;
        for (auto y : adj[x]) {
            self(self, y);
            sum += a[y];
            h[x] = std::max(h[x], 1 + h[y]);
            for (int i = 0; i <= h[y]; i++) {
                dp[x][i + 1] += dp[y][i];
            }
        }
        if (a[x] <= sum) {
            dp[x][0] += sum - a[x];
        } else {
            i64 t = a[x] - sum;
            for (int i = 0; i <= h[x]; i++) {
                i64 u = std::min(t, dp[x][i]);
                ans += u * i;
                t -= u;
                dp[x][i] -= u;
            }
        }
    };
    dfs(dfs, 0);

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}