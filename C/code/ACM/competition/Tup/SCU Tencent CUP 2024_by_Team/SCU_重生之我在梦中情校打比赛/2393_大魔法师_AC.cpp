#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[3][2005], v[3][2005], w[3][2005];
int n, m[3], pre[2005];
inline void Solve(int *f, int*v, int*w, int m) {
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= v[i]; j--) {
			f[j] = max(f[j - v[i]] + w[i], f[j]);
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < 3; i++) cin >> m[i];
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= m[i]; j++) {
			cin >> v[i][j] >> w[i][j];
		}
		Solve(f[i], v[i], w[i], m[i]);
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j + i <= n; j++) {
			int k = n - i - j;
			ans = max(ans, f[0][i] * f[1][j] * f[2][k]);
		}
	}
	cout << ans << endl;
	return 0;
}
/*
10 2 2 2
2 1
3 2
2 1
3 2
5 3
4 2
*/
