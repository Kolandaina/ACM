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
    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        a.push_back({std::min(x, y), std::max(x, y)});
    }
    std::sort(a.begin(), a.end());
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j].first < a[i].second && a[j].second > a[i].second) {
                flag = false;
                break;
            }
        }
    }
    if (flag) std::cout << "No" << endl;
    else std::cout << "Yes" << endl;
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
