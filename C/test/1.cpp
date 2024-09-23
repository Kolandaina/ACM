#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
int dp[101][101][10001];
inline void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        std::cin >> b[i];
        sum += a[i];
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= j * 100; ++k) {
                dp[i][j][k] = -INT_MAX;
            }
        }
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k <= j * 100; ++k) {
                if (dp[i - 1][j][k] >= 0) {
                    dp[i][j][k] = std::max(dp[i - 1][j][k], dp[i][j][k]);
                    dp[i][j + 1][k + a[i]] = std::max(dp[i - 1][j][k] + b[i] - a[i], dp[i][j + 1][k + a[i]]);
                }
            }
        }
    }
    for (int j = 1; j <= n; ++j) {
        int ans = 0;
        for (int k = 0; k <= j * 100; ++k) {
            if (dp[n][j][k] >= 0) {
                ans = std::max(ans, k * 2 + std::min(dp[n][j][k] * 2, sum - k));
            }
        }
        double res = (ans + 0.0) / 2;
        std::cout << fs(10) << res << " ";
    }
    std::cout << endl;
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