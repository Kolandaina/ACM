#include <bits/stdc++.h>

using i64 = long long;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

struct Max {
    int a = -1;
};
Max operator+(const Max &a, const Max &b) {
    return {std::max(a.a, b.a)};
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::mt19937 rng {std::chrono::steady_clock::now().time_since_epoch().count()};

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        // a[i] = rng() % n + 1;
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        // b[i] = rng() % n + 1;
        b[i]--;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        // c[i] = rng() % 1000 + 1;
    }

    std::vector<int> w(n);
    std::vector fen(1 << m, Fenwick<Max>(n));

    int ans = -1;
    for (int t = 0; t < 500; t++) {
        for (int i = 0; i < n; i++) {
            w[i] = rng() % m;
        }
        for (int i = 0; i < (1 << m); i++) {
            fen[i].init(n);
        }
        fen[0].add(0, {0});
        for (int i = 0; i < n; i++) {
            for (int s = (1 << m) - 1; s >= 0; s--) {
                if (s & (1 << w[b[i]])) {
                    continue;
                }
                int popc = __builtin_popcount(s);
                if (popc >= m) {
                    continue;
                }
                int v = fen[s].sum(a[i] + 1).a;
                if (v == -1) {
                    continue;
                }
                v += c[i];
                fen[s | 1 << w[b[i]]].add(a[i], {v});
                if (popc == m - 1) {
                    ans = std::max(ans, v);
                }
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}