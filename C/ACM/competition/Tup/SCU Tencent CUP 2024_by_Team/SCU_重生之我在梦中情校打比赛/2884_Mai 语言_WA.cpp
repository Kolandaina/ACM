#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 63;
 
ll n, m, k;
int cnt_d[N], used[N];

void charming() {
	cin >> n >> m >> k;
	for (int i = 0; i < 30; ++i) {
		int x = (1 << i), c = 0;
		while (x) {
			c += 1, x /= 10;
		}
		cnt_d[30 - i - 1] = m - 2 - c;
	}
	k = k * 1ll << 29;
	int p = 29, q = 0;
	while (p >= 0 && k >= 0) {
		if (cnt_d[p] <= 0) {
			--p;
			continue;
		}
		else if (1ll * cnt_d[p] * (1 << p) < k) {
			k -= 1ll * cnt_d[p] * (1 << p);
			used[p] = cnt_d[p];
			q += 1;
		}
		else {
			int c = k / (1 << p);
			if (1ll * c * (1 << p) == k) {
				used[p] = c;
				p -= 1;
				q += 1;
				k = 0;
				break;
			}
			else if (c > 0) {
				k -= 1ll * c * (1 << p);
				used[p] = c;
				q += 1;
			}
		}
		--p;
	}
	if (k > 0 || q > n) {
		cout << -1 << endl;
	}
	else {
		int idx = -1;
		for (int i = 0; i <= 29; ++i) {
			if (used[i] > 1) {idx = i; break;}
		}
		int dn = n - q;
		if (idx > -1) {
			used[idx] -= 1;
		}
		else {
			used[p + 1] -= 1;
			idx = p + 1;
			dn += 1;
		}
		
		if (p - dn + 1 < 0) {
			cout << -1 << endl;
		}
		else {
			int chk = (cnt_d[p - dn + 1] >= 2);
			if (!chk) {
				cout << -1 << endl;
			}
			else {
				for (int i = idx - 1; i >= p - dn + 1; --i) {
					used[i] += 1 + (i == p - dn + 1);
				}
				for (int i = 29; i >= 0; --i) {
					if (used[i]) {
						cout << "{" << (1 << (29 - i)) << "}";
						for (int j = 1; j <= used[i]; ++j) {
							cout << ",";
						}
						cout << endl;
					}
				}
			}
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

