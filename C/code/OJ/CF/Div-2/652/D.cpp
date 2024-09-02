#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
inline void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> w(n + 10);
    for (int i = 1; i <= n; i++) std::cin >> w[i];
    std::vector<std::vector<std::pair<int, int>>> g(n + 10);
    std::map<int, int> mp;
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        mp[x]++, mp[y]++;
        g[x].push_back({y, i});
        g[y].push_back({x, i});
    }
    std::vector<bool> vis(n + 10, false);
    std::vector<int> res;
    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (mp[i] <= w[i] && mp[i]) q.push(i);
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto [x, y] : g[t]) {
            if (!vis[y]) {
                vis[y] = true;
                res.push_back(y);
                mp[x]--;
                if (mp[x] <= w[x]) q.push(x);
            }
        }
    }
    if (res.size() < m)std::cout << "DEAD" << endl;
    else {
        std::reverse(res.begin(), res.end());
        std::cout << "ALIVE" << endl;
        for (auto x : res)std::cout << x << " ";
        std::cout << endl;
    }
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
