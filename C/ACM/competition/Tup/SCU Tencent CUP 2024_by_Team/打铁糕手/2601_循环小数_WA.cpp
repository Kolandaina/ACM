#include<bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int qpow(int x,int n){
	int ans=1;
	while(n){
		if(n&1){
			ans*=x;
		}
		x*=x;
		n>>=1;
	}
	return ans;
}

void solve() {
	
	int a,s,b,t;
	cin>>a>>s>>b>>t;
	int d=__gcd(qpow(a,s)-1,qpow(b,t)-1);
	if(d>1){
		int k=(qpow(b,t)-1)/d;
		cout<<k<<' '<<qpow(a,s)-1<<endl;
	}else{
		cout<<-1<<endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; cin >> t;
	
	while (t --) {
		solve();
	}
	return 0;
}

