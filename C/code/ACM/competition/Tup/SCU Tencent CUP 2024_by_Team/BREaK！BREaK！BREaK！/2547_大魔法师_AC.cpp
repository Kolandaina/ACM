#include <bits/stdc++.h>

typedef long long ll;

const int N = 2100;

int n, m1, m2, m3;
int f[3][N];

void solve()
{
	std::cin >> n >> m1 >> m2 >> m3;
	
	for(int i=1;i<=m1;i++) {
		int v, w; std::cin >> v >> w;
		for(int j=n-v;j>=0;j--) {
			f[0][j+v] = std::max(f[0][j+v], f[0][j]+w);
		}
	}
	
	for(int i=1;i<=m2;i++) {
		int v, w; std::cin >> v >> w;
		for(int j=n-v;j>=0;j--) {
			f[1][j+v] = std::max(f[1][j+v], f[1][j]+w);
		}
	}
	
	for(int i=1;i<=m3;i++) {
		int v, w; std::cin >> v >> w;
		for(int j=n-v;j>=0;j--) {
			f[2][j+v] = std::max(f[2][j+v], f[2][j]+w);
		}
	}
	
	ll ans = 0;
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++) {
			int len1 = i, len2 = j-i, len3 = n-j;
			ans = std::max(ans, 1ll*f[0][len1]*f[1][len2]*f[2][len3]);
		}
		
	std::cout << ans << "\n";
}

signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int t = 1;
	//std::cin >> t;
	for(int i=1;i<=t;i++)
		solve();
	return 0;
}
