#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 4e5 + 10;
const int mod = 998244353;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
template<typename T>
T ksm(T a, T b, T mod) {
    T res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
struct Combinatorics {
    int n, mod;
    std::vector<int> fac, inv;
    Combinatorics(int n, int mod) : n(n), mod(mod) {
        fac.resize(n + 1);
        inv.resize(n + 1);
        init();
    }
    void init() {
        fac[0] = inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = ksm(fac[i], mod - 2, mod);
        }
    }
    int C(int n, int m) {
        if (n < m) return 0;
        return (fac[n] * inv[n - m] % mod) * inv[m] % mod;
    }
};
inline void solve() {
    Combinatorics Com(N, mod);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        a.push_back({l, -1});
        a.push_back({r, 1});
    }
    std::sort(a.begin(), a.end());
    int cnt = 0, ans = 0;
    for (auto &[l, r] : a) {
        if (r == -1 && cnt >= k - 1) {
            ans = (ans + Com.C(cnt, k - 1)) % mod;
        }
        cnt -= r;
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
