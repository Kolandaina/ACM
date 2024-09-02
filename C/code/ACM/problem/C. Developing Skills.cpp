/*
https://codeforces.com/problemset/problem/581/C
*/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
bool cmp(const int &a, const int &b) {
    return a % 10 < b % 10;
}
inline void slove() {
    int n, k;
    std::cin >> n >> k;
    std::deque<int> a;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ans += x / 10;
        if (x != 100) a.emplace_back(x);
    }
    n = a.size();
    std::sort(a.begin(), a.end(), cmp);
    while (k && !a.empty()) {
        if (k < 10 - a.back() % 10)
            break;
        k -= 10 - a.back() % 10;
        a.back() += 10 - a.back() % 10;
        ans++;
        int x = a.back();
        a.pop_back();
        if (x != 100)
            a.emplace_front(x);
    }
    std::cout << ans << endl;
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