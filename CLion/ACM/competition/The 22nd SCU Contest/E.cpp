#include <bits/stdc++.h>

#define int long long
#define endl '\n'
const int N = 1e5;
const int mod = 1e9 + 7;
double w[N];

int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
        b = b >> 1;
    }
    return res;
}

void slove() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)std::cin >> w[i];
    std::sort(w + 1, w + n + 1);
    while (m--) {
        double x;
        int ans;
        std::cin >> x;
        int k1 = std::lower_bound(w + 1, w + n + 1, x) - w;
        int k2 = std::upper_bound(w + 1, w + n + 1, x) - w;
        int a = k1 - 1, b = k2 - k1, c = n - k2 + 1;
        ans = ((ksm(2, b) - 1) * (ksm(2, a + c)) + (ksm(2, a) - 1) * (ksm(2, c) - 1)) % mod;
        std::cout << ans << endl;
    }

}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    //std::cin >> t;
    while (t--) slove();
    return 0;
}