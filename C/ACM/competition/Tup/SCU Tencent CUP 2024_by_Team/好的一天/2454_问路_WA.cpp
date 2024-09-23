#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
	double n, m, k,r,x;
	std::cin >> r >> x;
//	cin>>r>>x;
//	std::cout << cos(x/r);
	if(r == 0) {
		printf("%.15f", 0);
	} else
		printf("%.15f",-x*(1-(1/cos(x/r))));
}

signed main () {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);

	int t = 1;
//	cin >> t;
	for(int i = 0; i < t; ++i) solve ();

	return 0;
}
