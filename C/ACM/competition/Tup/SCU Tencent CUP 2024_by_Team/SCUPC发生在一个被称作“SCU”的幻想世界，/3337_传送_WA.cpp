#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

typedef vector<int> vi;
typedef double db;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

struct T {
	int a, b, c, d;
	bool use;
	bool operator<(const T&t) const {
		if (a == t.a)
			return b >= t.b;
		else
			return a < t.a;
	}
} t[N], a[N];
int L[N], R[N];
int l[N], r[N];

void solve() {
	int n, m, mm = 0;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> t[i].a >> t[i].b >> t[i].c >> t[i].d;
		t[i].use = 1;
		L[i] = R[i] = 0;
	}
	sort(t + 1, t + m + 1);
	for (int i = 1; i <= m; ++i) {
		if (i + 1 <= m && t[i].b >= t[i + 1].a) {
			t[i].use = false;
			t[i + 1].a = t[i].a;
			t[i + 1].b = max(t[i + 1].b, t[i].b);
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (t[i].use) {
			a[++mm] = t[i];
		}
	}
	for (int i = 1; i <= mm; ++i) {
		if (i > 1 && a[i].c <= a[i - 1].b) {
			L[i] = L[i - 1];
			while (L[i] > 1 && a[i].c <= a[L[i] - 1].b) {
				--L[i];
			}
		} else {
			L[i] = i;
		}
	}
	for (int i = mm; i >= 1; --i) {
		if (i < mm && a[i].d >= a[i + 1].a) {
			R[i] = R[i + 1];
			while (R[i] < mm && a[i].d >= a[R[i] + 1].a) {
				++R[i];
			}
		} else {
			R[i] = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		l[i] = r[i] = i;
	}
	for (int i = 1; i <= mm; ++i) {
		for (int j = a[i].a; j <= a[i].b; ++j) {
			l[j] = min(l[j], a[L[i]].c);
			r[j] = max(r[j], a[R[i]].d);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << l[i] << ' ' << r[i] << '\n';
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int T;
	cin >> T;
	while (T--) solve();
	
	return 0;
}
