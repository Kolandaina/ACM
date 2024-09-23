#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 998244353;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
template <typename T>
constexpr T ksm(T a, T b) {
    T res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
inline void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    int inv = ksm(n, mod - 2);
    std::vector<int> f(n + 1, 0);
    f[1] = inv;
    int ans = f[1] * a[1] % mod;
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + (f[i - 1] * inv) % mod) % mod;
        ans = (ans + f[i] * a[i] % mod) % mod;
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
