#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

inline void slove() {
    double x, y, t, v, s, r, a;
    std::cin >> x >> y >> t >> v;
    r = sqrt(x * x + y * y);
    s = t * v - floor(t * v);
    a = s * 3.14159265358;
    std::cout << std::fixed << std::setprecision(10) << 2 * r * sin(a);
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