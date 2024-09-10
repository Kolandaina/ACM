#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
struct DSU {
    std::vector<int> fa, p, e, f;
    DSU(int n) {
        fa.resize(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
        p.resize(n + 1, 1);
        e.resize(n + 1);
        f.resize(n + 1);
    }
    int find(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) {
        if (x == y) f[find(x)] = 1;
        x = find(x), y = find(y);
        e[x]++;
        if (x == y) return false;
        if (x < y) std::swap(x, y);
        fa[y] = x;
        f[x] |= f[y], p[x] += p[y], e[x] += e[y];
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool F(int x) {
        return f[find(x)];
    }
    int size(int x) {
        return p[find(x)];
    }
    int E(int x) {
        return e[find(x)];
    }
};

inline void solve() {
    int n, m;
    std::cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        dsu.merge(x, y);
    }
    bool flag = true;
    std::vector<int> cnt;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.fa[i] == i) {
            int res = (dsu.size(i) * (dsu.size(i) - 1)) / 2;
            if (res != dsu.E(i)) {
                flag = false;
                ans += res - dsu.E(i);
            } else {
                cnt.push_back(dsu.size(i));
            }
        }
    }
    if (flag) {
        std::sort(cnt.begin(), cnt.end());
        std::cout << cnt[0] * cnt[1] << endl;
    } else {
        std::cout << ans << endl;
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
