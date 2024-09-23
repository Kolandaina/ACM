#include<bits/stdc++.h>
#define int long long
using namespace std;
const double pi = acos(-1);
void solve(){
	double R, X;
	scanf("%lf%lf", &R, &X);
	//cin >> R >> X;
	
	double ans = X / abs(cos(X / R) ) - X; 
	int C = 2 * R * pi;
	while(ans >= C) ans -= C;
	if(ans >= (C / 2)) ans = C - ans;
	printf("%.9f", ans); 
}
signed main(){
	int T;
	T = 1;	
	while(T--){
		solve();
	}	
	return 0;
}
