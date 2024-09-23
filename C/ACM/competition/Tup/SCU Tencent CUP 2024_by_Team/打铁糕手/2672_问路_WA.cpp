#include <bits/stdc++.h>

#define int long long
#define PI acos(-1)

using namespace std;



/*

*/

void solve(){
	
	double r, x; cin >> r >> x;
	double y =  1.0 / cos(x / r) - 1.0;
	printf("%.15f\n", y * x);
	
	
	
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
