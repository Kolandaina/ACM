#include <bits/stdc++.h>

#define int long long
#define PI acos(-1)

using namespace std;


void solve(){
	double R, x;
	scanf("%lf%lf", &R, &x);
	R = (long double)R;
	x = (long double)x;
	if (x == 0) {
		printf("%.15f", 0.0);
		return ;
	}
	long double r = R * 1.0 * cos(x * 1.0 / R);
	long double l = 2 * PI * r;
//	cout << r << ' ' << l << '\n';
	long double T = x - floor(x / l) * l;
//	double T = x;
	long double res = min(l - T, T);
//	cout << res << '\n';
	long double y =  res * (R / r - 1);
	printf("%.15Lf\n", y);
	
	
	
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
