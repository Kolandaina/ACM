#include <bits/stdc++.h>

typedef long long ll;

#define int long long

const int N = 1e5+10, mod = 1e9+7;

int n, q;
double a[N];
ll e2[N];


void init() {
	e2[0] = 1;
	for(int i=1;i<N;i++) e2[i] = 1ll*e2[i-1]*2%mod;
	

}

void solve()
{
	std::cin >> n >> q;
	for(int i=1;i<=n;i++) std::cin >> a[i];
	std::sort(a+1,a+n+1);
	
	for(int i=1;i<=q;i++) {
		double x; std::cin >> x;
		
		int ind = std::lower_bound(a+1,a+n+1,x) - a;
		int ne = std::upper_bound(a+1,a+n+1,x) - a;
		int eq = ne - ind;
		int upper = n-ne+1;
		int lower = ind-1;
		
		if(!eq&&(!upper||!lower)) {
			std::cout << 0 << "\n";
			continue;
		}
		
		ll ans = 0;
		ans = 1ll*(e2[eq]-1)*e2[upper]%mod*e2[lower]%mod;
		ans = (ans+1ll*(e2[upper]-1)%mod*(e2[lower]-1)%mod)%mod;
		std::cout << (ans%mod+mod)%mod << "\n";
	}
}

signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	init();
	
	int t = 1;
	//std::cin >> t;
	for(int i=1;i<=t;i++)
		solve();
	return 0;
}
