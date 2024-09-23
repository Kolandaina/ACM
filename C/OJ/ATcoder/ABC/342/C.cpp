#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
inline void solve() {
    int n, q;
    std::cin >> n;
    std::string s;
    std::map<char, char> mp;
    std::cin >> s;
    std::cin >> q;
    for (int i = 'a'; i <= 'z'; i++)  mp[char(i)] = char(i);
    std::vector<char> c(q + 1), d(q + 1);
    for (int i = 1; i <= q; i++)std::cin >> c[i] >> d[i];
    for (int i = q; i >= 1; i--) mp[c[i]] = mp[d[i]];
    for (auto &c : s) {
        std::cout << mp[c];
    }
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
