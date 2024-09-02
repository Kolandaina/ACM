#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
inline void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> in(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++, in[v]++;
    }
    if (n == 1)std::cout << "Ayush" << endl;
    else {
        if (in[x] == 1)std::cout << "Ayush" << endl;
        else if (n % 2)std::cout << "Ashish" << endl;
        else std::cout << "Ayush" << endl;
    }
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std:: cin >> t;
    while (t--) solve();
    return 0;
}