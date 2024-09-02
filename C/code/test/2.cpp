#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
struct BIT {
    int n;
    std::vector<int> w;
    BIT() {}
    BIT(int n) {
        this->n = n;
        w.resize(n + 1);
    }
    void add(int x, int k) {
        for (; x <= n; x += x & -x) {
            w[x] += k;
        }
    }
    void add(int x, int y, int k) {
        add(x, k), add(y, -k);
    }
    int ask(int x) {
        int ans = 0;
        for (; x; x -= x & -x) {
            ans += w[x];
        }
        return ans;
    }
    int ask(int x, int y) {
        return ask(y) - ask(x - 1);
    }
};
inline void solve() {
    std::string s;
    int len, q;
    std::cin >> s;
    len = s.length();
    std::vector<BIT> tree(26, BIT(len));
    for (int i = 0; i < len; i++) {
        tree[s[i] - 'a'].add(i + 1, 1);
    }
    std::cin >> q;
    while (q--) {
        int opt, x, y;
        char z;
        std::cin >> opt;
        if (opt == 1) {
            std::cin >> x >> z;
            tree[s[x - 1] - 'a'].add(x, -1);
            tree[z - 'a'].add(x, 1);
            s[x - 1] = z;
        } else if (opt == 2) {
            std::cin >> x >> y;
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                if (tree[i].ask(x, y) > 0) {
                    ans++;
                }
            }
            std::cout << ans << endl;
        }
    }
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    //std:: cin >> t;
    while (t--) solve();
    return 0;
}
