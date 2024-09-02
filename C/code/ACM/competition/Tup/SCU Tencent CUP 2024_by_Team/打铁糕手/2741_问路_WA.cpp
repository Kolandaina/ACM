#include <bits/stdc++.h>

#define int long long
#define PI acos(-1)

using namespace std;



/*

*/

void solve(){
	long double r, x; cin >> r >> x;
	if (x == 0) {
		printf("%.16Lf", 0);
		return ;
	}
	long double y =  1.0 / cos(x / r) - 1.0;
	printf("%.16Lf\n", y * x);
	
	
	
}

signed main(){
		
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
//	cin >> t;
	while(t--)
		solve();
	
	return 0;
}
