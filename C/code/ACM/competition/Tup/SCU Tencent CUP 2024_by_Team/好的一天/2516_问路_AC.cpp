#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
//	cout<<1/cos(1.5);
	double n, m, k,r,x;
	double p=acos(-1.0);
//	cout<<p;
	std::cin >> r >> x;
//	cin>>r>>x;
//	std::cout << cos(x/r);
	if(r == 0) {
		printf("%.15f", 0);
	} else{
		m=x*((1/cos(x/r))-1);
//		cout<<m<<'\n';
		while(m>2*p*r){
			m-=2*p*r;
		}
		if(m>(p*r)){
			printf("%.15f",2*p*r-m);
		}
		else{
		printf("%.15f",m);	
		}
	}
		
}

signed main () {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);

	int t = 1;
//	cin >> t;
	for(int i = 0; i < t; ++i) solve ();

	return 0;
}
