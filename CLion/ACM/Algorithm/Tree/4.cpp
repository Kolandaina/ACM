#include <iostream>
#include <vector>

#define int long long
constexpr int N = 1e5 + 10;
int mod;
struct segmentTree {
    int l, r;
    int sum, mul, add;
} t[N << 2];

void pushup(int p) {
    t[p].sum = (t[p << 1].sum + t[p << 1 | 1].sum) % mod;
}

void pushdown(int p) {
    t[p << 1].sum = (t[p << 1].sum * t[p].mul + (t[p << 1].r - t[p << 1].l + 1) * t[p].add) % mod;
    t[p << 1 | 1].sum = (t[p << 1 | 1].sum * t[p].mul + (t[p << 1 | 1].r - t[p << 1 | 1].l + 1) * t[p].add) % mod;
    t[p << 1].mul = (t[p << 1].mul * t[p].mul) % mod;
    t[p << 1 | 1].mul = (t[p << 1 | 1].mul * t[p].mul) % mod;
    t[p << 1].add = (t[p << 1].add * t[p].mul + t[p].add) % mod;
    t[p << 1 | 1].add = (t[p << 1 | 1].add * t[p].mul + t[p].add) % mod;
    t[p].mul = 1, t[p].add = 0;
}

std::vector<int> a;

void build(int p, int l, int r) {
    t[p] = {l, r, 0, 1, 0};
    if (l == r) {
        t[p].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

void modify(int p, int l, int r, int mul, int add) {
    if (t[p].r <= r && t[p].l >= l) {
        t[p].sum = (t[p].sum * mul + (t[p].r - t[p].l + 1) * add) % mod;
        t[p].mul = (t[p].mul * mul) % mod;
        t[p].add = (t[p].add * mul + add) % mod;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (r <= mid) modify(p << 1, l, r, mul, add);
    else if (l > mid) modify(p << 1 | 1, l, r, mul, add);
    else
        modify(p << 1, l, mid, mul, add), modify(p << 1 | 1, mid + 1, r, mul,
                                                 add);
    pushup(p);
}

int query(int p, int l, int r) {
    if (t[p].r <= r && t[p].l >= l) {
        return t[p].sum;
    }
    pushdown(p);
    int res{};
    int mid = (t[p].l + t[p].r) >> 1;
    if (r <= mid) res += query(p << 1, l, r);
    else if (l > mid) res += query(p << 1 | 1, l, r);
    else res += query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r);
    return res % mod;
}

signed main() {
    int n, m;
    std::cin >> n >> m >> mod;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int op, l, r, k;
        std::cin >> op;
        if (op == 1) {
            std::cin >> l >> r >> k;
            modify(1, l, r, k, 0);
        } else if (op == 2) {
            std::cin >> l >> r >> k;
            modify(1, l, r, 1, k);
        } else {
            std::cin >> l >> r;
            std::cout << query(1, l, r) << std::endl;
        }
    }
}