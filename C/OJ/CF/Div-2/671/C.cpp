#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
inline void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    bool flag1 = true, flag2 = false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] != x) flag1 = false;
        if (a[i] == x) flag2 = true;
        sum += a[i];
    }
    if (flag1)std::cout << 0 << endl;
    else if (flag2 || sum == x * n)std::cout << 1 << endl;
    else std::cout << 2 << endl;
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