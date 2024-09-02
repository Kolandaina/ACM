#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 10;

int a[N + 1];

struct tree {
    int l, r;
    int cnt;
    int tag;
} t[N << 2];

void pushup(int p) {
    t[p].cnt = t[p << 1].cnt + t[p << 1 | 1].cnt;
}

void pushdown(int p) {
    if (t[p].tag) {
        t[p << 1].cnt += t[p].tag * (t[p << 1].r - t[p << 1].l + 1);
        t[p << 1].tag += t[p].tag;
        t[p << 1 | 1].cnt += t[p].tag * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1);
        t[p << 1 | 1].tag += t[p].tag;
        t[p].tag = 0;
    }
}

void build(int p, int l, int r) {
    t[p] = {l, r};
    if (l == r) {
        t[p].cnt = a[l] % 2;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

void modify(int p, int l, int r, int k) {
    if (t[p].l >= l && t[p].r <= r) {
        t[p].cnt += k * ((t[p].r - t[p].l + 1) - t[p].cnt);
        t[p].tag += k;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid) {
        modify(p << 1, l, r, k);
    }
    if (r > mid) {
        modify(p << 1 | 1, l, r, k);
    }
    pushup(p);
}

int query(int p, int l, int r) {
    if (t[p].l >= l && t[p].r <= r) {
        return t[p].cnt;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    int res = 0;
    if (l <= mid) {
        res += query(p << 1, l, r);
    }
    if (r > mid) {
        res += query(p << 1 | 1, l, r);
    }
    return res;
}

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int op, x, y, k;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            modify(1, x, y, k);
        } else {
            cin >> x >> y;
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}