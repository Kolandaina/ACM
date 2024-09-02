#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
inline void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    std::vector<int> res1, res2;
    std::vector<int> deep(n + 1, 0);
    std::function<void(int, int)> dfs = [&](int u, int fa) {
        if (deep[u] % 2 == 0)res1.push_back(u);
        else res2.push_back(u);
        for (auto v : g[u]) {
            if (v == fa) continue;
            if (!deep[v]) {
                deep[v] = deep[u] + 1;
                dfs(v, u);
            }
        }
    };
    std::vector<int> ans;
    std::vector<int> st;
    std::vector<bool> vis(n + 1);
    auto  dfs2 = [&](auto & self, int u, int fa)->void {
        st.push_back(u);
        vis[u] = true;
        for (auto v : g[u]) {
            if (v == fa) continue;
            if (vis[v]) {
                while (st.back() != v) {
                    ans.push_back(st.back());
                    st.pop_back();
                }
                ans.push_back(v);
                for (auto i : ans)std::cout << i << " ";
                std::cout << endl;
                if (ans.size() <= k) {
                    std::cout << 2 << endl;
                    std::cout << ans.size() << endl;
                    for (auto i : ans)std::cout << i << " ";
                    std::cout << endl;
                } else {
                    std::cout << "dsfsdf" << endl;
                    std::cout << 1 << endl;
                    for (int i = 0; i < ans.size(); i += 2)std::cout << ans[i] << " ";
                    std::cout << endl;
                }
                exit(0);
            }
            self(self, v, u);
        }
        st.pop_back();
    };
    if (m == n - 1) {
        dfs(1, 0);
        if (res1.size() < res2.size()) {
            std::swap(res1, res2);
        }
        std::cout << 1 << endl;
        for (int i = 0; i < (k + 1) / 2; i++) {
            std::cout << res1[i] << " ";
        }
        std::cout << endl;
    } else {
        dfs2(dfs2, 1, 0);
        if (ans.size() <= k) {
            std::cout << 2 << endl;
            std::cout << ans.size() << endl;
            for (auto i : ans)std::cout << i << " ";
            std::cout << endl;
        } else {
            std::cout << 1 << endl;
            for (int i = 0; i < ans.size(); i += 2)std::cout << ans[i] << " ";
            std::cout << endl;
        }
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