#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

inline void slove() {
    double a, b;
    std::cin >> a >> b;
    double ans1, ans2;
    ans1 = a / 2 + b / 2;
    ans2 = (sqrt(3) / 2) * a - (sqrt(3) / 2) * b;
    printf("%.6lf %.6lf\n", ans1, ans2);
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