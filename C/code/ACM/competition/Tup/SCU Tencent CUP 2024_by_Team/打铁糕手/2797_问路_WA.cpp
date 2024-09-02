#include <bits/stdc++.h>

//#define int long long
#define PI acos(-1)

using namespace std;



/*

*/

void solve(){
	int r, x;
	scanf("%d%d", &r, &x);
	if (x == 0) {
		printf("%.16f", 0);
		return ;
	}
	double y =  1.0 / cos(x * 1.0 / r) * 1.0 - 1.0;
	printf("%.16f\n", y * x);
	
	
	
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
