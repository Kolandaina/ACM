/*
https://codeforces.com/problemset/problem/459/B
*/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp[a[i]]++;
    }
    auto maxn = mp.rbegin();
    auto minn = mp.begin();
    if (maxn->first == minn->first) {
        std::cout << 0 << " " << (n * (n - 1)) / 2 << endl;
        return;
    }
    std::cout << maxn->first - minn->first << " " << maxn->second *minn->second << endl;
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}