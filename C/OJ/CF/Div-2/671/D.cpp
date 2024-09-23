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
    std::vector<int> a(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    std::sort(a.begin() + 1, a.end());
    int pos1 = 1, pos2 = n / 2 + 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)ans[i] = a[pos1++];
        else ans[i] = a[pos2++];
    }
    for (int i = 1; i < n; i++) {
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) sum++;
    }
    std::cout << sum << endl;
    for (int i = 1; i <= n; i++) std::cout << ans[i] << " ";
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