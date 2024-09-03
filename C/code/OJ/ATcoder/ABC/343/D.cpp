#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};
struct Info {
    int mx1 = -1;
    int cnt1 = 0;
    int mx2 = -2;
    int cnt2 = 0;
};
Info operator+(Info a, Info b) {
    if (a.mx1 == b.mx1) {
        if (a.mx2 < b.mx2) {
            std::swap(a, b);
        }
        a.cnt1 += b.cnt1;
        if (a.mx2 == b.mx2) {
            a.cnt2 += b.cnt2;
        }
        return a;
    }
    if (a.mx1 < b.mx1) {
        std::swap(a, b);
    }
    if (b.mx1 > a.mx2) {
        a.mx2 = b.mx1;
        a.cnt2 = b.cnt1;
    } else if (b.mx1 == a.mx2) {
        a.cnt2 += b.cnt1;
    }
    return a;
}
inline void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    SegmentTree<Info> seg(N);
    for (int i = 0; i < n; i++) {
        seg.modify(i, Info{a[i], 1, -1, 0});
    }
    while (q--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        x--;
        if (op == 1) {
            seg.modify(x, Info{y, 1, -1, 0});
        } else {
            std::cout << seg.rangeQuery(x, y).cnt2 << endl;
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