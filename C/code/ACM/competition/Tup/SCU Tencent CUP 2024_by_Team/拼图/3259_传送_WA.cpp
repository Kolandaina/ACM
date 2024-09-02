#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 5;
int n, m;
int Max[MaxN << 2];
int Min[MaxN << 2];
int tagmax[MaxN << 2];
int tagmin[MaxN << 2];
void build(int p, int l, int r) {
	tagmax[p] = tagmin[p] = -1;
	if (l == r) {
		Max[p] = Min[p] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	Max[p] = max(Max[p << 1], Max[p << 1 | 1]);
	Min[p] = min(Min[p << 1], Min[p << 1 | 1]);
}
void pushdown_max(int p) {
	if (tagmax[p] == -1) return;
	Max[p << 1] = tagmax[p];
	Max[p << 1 | 1] = tagmax[p];
	tagmax[p << 1] = tagmax[p];
	tagmax[p << 1 | 1] = tagmax[p];
	tagmax[p] = -1;
}
void pushdown_min(int p) {
	if (tagmin[p] == -1) return;
	Max[p << 1] = tagmin[p];
	Max[p << 1 | 1] = tagmin[p];
	tagmin[p << 1] = tagmin[p];
	tagmin[p << 1 | 1] = tagmin[p];
	tagmin[p] = -1;
}
int getmax(int p, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return Max[p];
	}
	int mid = (l + r) >> 1;
	int res = 0;
	pushdown_max(p);
	if (ql <= mid) res = max(res, getmax(p << 1, l, mid, ql, qr));
	if (qr > mid) res = max(res, getmax(p << 1 | 1, mid + 1, r, ql, qr));
	return res;
}
int getmin(int p, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return Min[p];
	}
	int mid = (l + r) >> 1;
	int res = n + 1;
	pushdown_min(p);
	if (ql <= mid) res = min(res, getmin(p << 1, l, mid, ql, qr));
	if (qr > mid) res = min(res, getmin(p << 1 | 1, mid + 1, r, ql, qr));
	return res;
}
struct Node {
	int l1, r1; // big
	int l2, r2; // small
};
bool cmp1(Node a, Node b) {
	if (a.l1 != b.l1) return a.l1 < b.l1;
	return a.r1 < b.r1;
}
bool cmp2(Node a, Node b) {
	if (a.r1 != b.r1) return a.r1 > b.r1;
	return a.l1 > b.l1;
}
Node p[MaxN];
void assignmax(int p, int l, int r, int ql, int qr, int v) {
	if (ql <= l && r <= qr) {
		tagmax[p] = v;
		Max[p] = v;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown_max(p);
	if (ql <= mid) assignmax(p << 1, l, mid, ql, qr, v);
	if (qr > mid) assignmax(p << 1 | 1, mid + 1, r, ql, qr, v);
	Max[p] = max(Max[p << 1], Max[p << 1 | 1]);
}
void assignmin(int p, int l, int r, int ql, int qr, int v) {
	if (ql <= l && r <= qr) {
		tagmin[p] = v;
		Min[p] = v;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown_min(p);
	if (ql <= mid) assignmin(p << 1, l, mid, ql, qr, v);
	if (qr > mid) assignmin(p << 1 | 1, mid + 1, r, ql, qr, v);
	Min[p] = min(Min[p << 1], Min[p << 1 | 1]);
}
int Ansmax[MaxN], Ansmin[MaxN];
void getAns(int p, int l, int r) {
	if (l == r) {
		Ansmax[l] = Max[p];
		Ansmin[l] = Min[p];
		return;
	}
	int mid = (l + r) >> 1;
	pushdown_max(p);
	pushdown_min(p);
	getAns(p << 1, l, mid);
	getAns(p << 1 | 1, mid + 1, r);
}
void solve() {
	cin >> n >> m;
	build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		cin >> p[i].l2 >> p[i].r2;
		cin >> p[i].l1 >> p[i].r1;
	}
	sort(p + 1, p + m + 1, cmp1);
	for (int i = 1; i <= m; ++i) {
		int v = getmin(1, 1, n, p[i].l1, p[i].r1);
		assignmin(1, 1, n, p[i].l2, p[i].r2, v);
	}
	sort(p + 1, p + m + 1, cmp2);
	for (int i = 1; i <= m; ++i) {
		int v = getmax(1, 1, n, p[i].l1, p[i].r1);
//		cout << p[i].l1 << " " << p[i].r1 << " " << v << endl;
		assignmax(1, 1, n, p[i].l2, p[i].r2, v);
	}
	getAns(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		cout << Ansmin[i] << " " << Ansmax[i] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

