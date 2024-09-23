#include <bits/stdc++.h>

#define int long long

void solve() {
	int n;
	std::vector<int> m(3);
	std::cin >> n;
	for(int i = 0; i < 3; i++) std::cin >> m[i];
	std::vector<std::vector<int> > f(3, std::vector<int>(n + 1));
	std::vector<std::vector<int> > v(3), w(3);

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < m[i]; j++) {
			int a, b;
			std::cin >> a >> b;
			v[i].push_back(a);
			w[i].push_back(b);
		}
	}

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < m[i]; j++) {
			for(int t = n; t >= v[i][j]; t--) {
				f[i][t] = std::max(f[i][t], f[i][t - v[i][j]] + w[i][j]);
			}
		}
	}

	int ans = 0;

	for(int i = 0; i <= n; i++) {
		for(int j = 0; i + j <= n; j++) {
			int k = n - i - j;
			ans = std::max(ans, f[0][i] * f[1][j] * f[2][k]);
		}
	}
	std::cout << ans;
}

signed main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int t = 1;
	for(int i = 0; i < t; ++i) solve ();

	return 0;
}
