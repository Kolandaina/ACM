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
    std::vector<int> b(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum += a[i];
        b[i] = a[i] % i;
    }
    if (sum % n != 0) {
        std::cout << -1 << endl;
        return;
    }
    std::cout << 3 * (n - 1) << endl;
    for (int i = 2; i <= n; i++) {
        std::cout << 1 << " " << i << " " << (i - b[i]) % i << endl;
        if (a[i] % i != 0) {
            a[1] = a[1] - ((i - b[i]) % i);
            a[i] = a[i] + ((i - b[i]) % i);
        }
        std::cout << i << " " << 1 << " " << a[i] / i << endl;
    }
    for (int i = 2; i <= n; i++) {
        std::cout << 1 << " " << i << " " << sum / n << endl;
    }
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std:: cin >> t;
    while (t--) solve();
    return 0;
}
