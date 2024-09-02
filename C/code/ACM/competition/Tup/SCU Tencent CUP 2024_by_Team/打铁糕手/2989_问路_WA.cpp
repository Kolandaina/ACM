#include <bits/stdc++.h>

#define int long long
#define PI acos(-1)

using namespace std;



/*

*/

void solve(){
	int R, x;
	scanf("%lld%lld", &R, &x);
	if (x == 0) {
		printf("%.15f", 0.0);
		return ;
	}
	double r = R * 1.0 * cos(x * 1.0 / R);
	double l = 2 * PI * r;
//	cout << r << ' ' << l << '\n';
	double tt;
	if (x <= l) tt = x;
	else {
		int T = floor(x * 1.0 / l);
		tt = x - T * l;
	}
//	cout << tt << '\n';
	double res = min(l - tt, tt);
//	cout << res << '\n';
	double y =  (res * 1.0 * R) / r - res;
	printf("%.15f\n", y);
	
	
	
}

signed main(){
		
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	int t = 1;
//	cin >> t;
	while(t--)
		solve();
	
	return 0;
}
