#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
inline void solve() {
    int n, ans = 0;
    std::cin >> n;
    std::vector<int> q(n + 1), a(n + 1), b(n + 1), tmp(n + 1);
    for (int i = 1; i <= n; ++ i) std::cin >> q[i], tmp[i] = q[i];
    for (int i = 1; i <= n; ++ i) std::cin >> a[i];
    for (int i = 1; i <= n; ++ i) std::cin >> b[i];
    for (int i = 0; i <= 1e6; ++ i) {
        for (int j = 1; j <= n; ++ j) q[j] = tmp[j];
        bool f = 0;
        for (int j = 1; j <= n; ++ j) {
            q[j] -= a[j] * i;
            if (q[j] < 0) {
                f = 1;
                break;
            }
        }
        if (f) break;
        int minn = 1e18;
        for (int j = 1; j <= n; ++ j) if (b[j]) minn = std::min(minn, q[j] / b[j]);
        ans = std::max(ans, i + minn);
    }
    std::cout << ans << endl;
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
