#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 2e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

inline void slove() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(N+ 1, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        a[x] += i;
    }
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << a[x] * a[y]<<endl;

    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}