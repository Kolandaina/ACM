#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const double eps = 1e-8;
const int MOD = 1e9 + 7;
 
int n, q;
int w[N], POW2[N];

void charming() {
	cin >> n >> q;
	POW2[0] = 1;
	for (int i = 1; i <= n; ++i) POW2[i] = 1ll * POW2[i - 1] * 2 % MOD;
	for (int i = 1; i <= n; ++i){
		double val; cin >> val;
		w[i] = (val * 1000 + eps);
		// cout << w[i] << " ";
	}
	// cout << endl;
	sort(w + 1, w + 1 + n);
	for (int i = 1, x; i <= q; ++i) {
		double val; cin >> val;
		x = (val * 1000 + eps);
		
		// cout << "query " << x << endl;
		if (x > w[n] || x < w[1]) {
			cout << 0 << endl;
			continue;
		}
		else {
			int ans = POW2[n] - 1;
			if (x > w[1]) {
				int l1 = 1, r1 = n, k1 = 1;
				while (l1 <= r1) {
					// cout << l1 << " " << r1 << " " << k1 << endl;
					int mid = l1 + r1 >> 1;
					if (w[mid] < x) l1 = mid + 1, k1 = mid;
					else r1 = mid - 1;
				}
				ans -= POW2[k1] - 1;
			}
			if (x < w[n]) {
				int l2 = 1, r2 = n, k2 = n;
				while (l2 <= r2) {
					// cout << l2 << " " << r2 << " " << k2 << endl;
					int mid = l2 + r2 >> 1;
					if (w[mid] > x) r2 = mid - 1, k2 = mid;
					else l2 = mid + 1;
				}
				ans -= POW2[n - k2 + 1] - 1;
			}
			ans = ((ans % MOD) + MOD) % MOD;
			cout << ans << endl;
		}
	}
	
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	charming();
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
