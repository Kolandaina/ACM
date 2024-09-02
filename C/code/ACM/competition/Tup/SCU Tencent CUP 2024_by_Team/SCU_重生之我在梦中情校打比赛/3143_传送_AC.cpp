#pragma GCC optmize("Ofast")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

bool cmp (pair<pair<int, int>, pair<int, int> > x, pair <pair<int, int>, pair<int, int> > y) {
	return x.first.first < y.first.first;
}

int t, n, m;

struct SegmentTree {
	int r_mx[N << 2], l_mn[N << 2], lazy_mx[N << 2], lazy_mn[N << 2];
	
	void Build (int rt, int l, int r) {
		lazy_mx[rt] = 0, lazy_mn[rt] = N;
		if (l == r) {r_mx[rt] = l_mn[rt] = l; return;}
		int mid = l + r >> 1;
		Build(rt << 1, l, mid);
		Build(rt << 1 | 1, mid + 1, r);
		r_mx[rt] = max(r_mx[rt << 1], r_mx[rt << 1 | 1]);
		l_mn[rt] = min(l_mn[rt << 1], l_mn[rt << 1 | 1]);
	}
	
	void PushDown(int rt) {
		if (lazy_mx[rt]) {
			r_mx[rt << 1] = max(r_mx[rt << 1], lazy_mx[rt]);
			r_mx[rt << 1 | 1] = max(r_mx[rt << 1 | 1], lazy_mx[rt]);
			lazy_mx[rt << 1] = max(lazy_mx[rt << 1], lazy_mx[rt]);
			lazy_mx[rt << 1 | 1] = max(lazy_mx[rt << 1 | 1], lazy_mx[rt]);
			lazy_mx[rt] = 0;
		}
		if (lazy_mn[rt] < N) {
			l_mn[rt << 1] = min(l_mn[rt << 1], lazy_mn[rt]);
			l_mn[rt << 1 | 1] = min(l_mn[rt << 1 | 1], lazy_mn[rt]);
			lazy_mn[rt << 1] = min(lazy_mn[rt << 1], lazy_mn[rt]);
			lazy_mn[rt << 1 | 1] = min(lazy_mn[rt << 1 | 1], lazy_mn[rt]); 		
			lazy_mn[rt] = N;	
		}
	}
	
	void Modify (int rt, int l, int r, int ql, int qr, int k, int type) {
		if (l >= ql && r <= qr) {
			if (type == 1) r_mx[rt] = max(r_mx[rt], k), lazy_mx[rt] = max(lazy_mx[rt], k);
			else l_mn[rt] = min(l_mn[rt], k), lazy_mn[rt] = min(lazy_mn[rt], k);
			return;
		}
		PushDown(rt);
		int mid = l + r >> 1;
		if (ql <= mid) Modify(rt << 1, l, mid, ql, qr, k, type);
		if (qr > mid) Modify(rt << 1 | 1, mid + 1, r, ql, qr, k, type);
		r_mx[rt] = max(r_mx[rt << 1], r_mx[rt << 1 | 1]);
		l_mn[rt] = min(l_mn[rt << 1], l_mn[rt << 1 | 1]);
	}	
	
	int Query(int rt, int l, int r, int ql, int qr, int type) {
		if (l >= ql && r <= qr) {
			if (type == 1) return r_mx[rt];
			else return l_mn[rt];
		}
		PushDown(rt);
		int mid = l + r >> 1, ans = (type == 1 ? 0 : N);
		if (ql <= mid) {
			int ret = Query(rt << 1, l, mid, ql, qr, type);
			if (type == 1) ans = max(ans, ret);
			else ans = min(ans, ret);
		}
		if (qr > mid) {
			int ret = Query(rt << 1 | 1, mid + 1, r, ql, qr, type);
			if (type == 1) ans = max(ans, ret);
			else ans = min(ans, ret);
		}
		return ans;
	}
} tree;

void charming() {
	cin >> n >> m;
	vector<pair<pair<int, int>, pair<int, int> > > seg(m);
	for (int i = 0; i < m; ++i) {
		cin >> seg[i].first.first >> seg[i].first.second;
		cin >> seg[i].second.first >> seg[i].second.second;
	}
	sort(seg.begin(), seg.end(), cmp);
	vector<pair<pair<int, int>, pair<int, int> > > nseg;
	for (int i = 0; i < m; ++i) {
		if (nseg.empty () || nseg.back().first.second < seg[i].first.first) {
			nseg.emplace_back(seg[i]);
		}
		else {
			nseg.back().first.second = max(nseg.back().first.second, seg[i].first.second);
			nseg.back().second.first = min(nseg.back().second.first, seg[i].second.first);
			nseg.back().second.second = max(nseg.back().second.second, seg[i].second.second);
		}
	}
	
	vector<pair<int, int> > ans (n + 1);
	for (int i = 1; i <= n; ++i) ans[i] = make_pair(i, i);
	tree.Build(1, 1, n);
	for (int i = 0; i < m; ++i) {
		int a = seg[i].first.first, b = seg[i].first.second;
		int c = seg[i].second.first, d = seg[i].second.second;
		tree.Modify(1, 1, n, a, b, c, 0);
		tree.Modify(1, 1, n, a, b, d, 1);
	}
	seg = nseg; m = seg.size();
	for (int i = 0, lst_l, lst_r; i < m; ++i) {
		int a = seg[i].first.first, b = seg[i].first.second;
		int c = seg[i].second.first, d = seg[i].second.second;
		lst_l = c, lst_r = d;
		while (true) {
			int l_mn = tree.Query(1, 1, n, lst_l, lst_r, 0);
			int r_mx = tree.Query(1, 1, n, lst_l, lst_r, 1);
			if (l_mn == lst_l && r_mx == lst_r) break;
			else lst_l = l_mn, lst_r = r_mx;
		}
		seg[i].second.first = lst_l, seg[i].second.second = lst_r;
		if (lst_l < c) tree.Modify(1, 1, n, a, b, lst_l, 0);
		if (lst_r > d) tree.Modify(1, 1, n, a, b, lst_r, 1);
		for (int j = a; j <= b; ++j) {
			ans[j].first = lst_l, ans[j].second = lst_r;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) charming();
	return 0;
}

/*
3 3
10.000
15.000
16.000
00.000
15.000
15.999
*/
