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
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    std::vector<int> res;
    for (int i = 2; i * i <= N; i++)res.push_back(i * i);
    std::map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        for (auto j : res) {
            if (a[i] >= j) {
                if (a[i] % j == 0) {
                    while (a[i] % j == 0) a[i] /= j;
                }
            } else break;
        }
        mp[a[i]]++;
    }
    int ans = 0;
    for (auto [x, y] : mp) {
        if (y >= 2)ans = ans + y * (y - 1) / 2;
        if (x == 0)ans += y * (n - y);
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
