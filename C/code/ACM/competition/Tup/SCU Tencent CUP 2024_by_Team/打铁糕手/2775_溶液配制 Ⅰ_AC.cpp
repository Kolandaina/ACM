#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

double a[100005];
map<double,int>hm;

int qpow(int x,int n){
	int ans=1;
	while(n){
		if(n&1){
			ans*=x;
			ans%=mod;
		}
		x*=x;
		x%=mod;
		n>>=1;
	}
	return ans;
}

void solve() {
	
	int n,q,s=0;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
		hm[a[i]]++;
	}
	sort(a,a+n);
	for(int i=0;i<q;i++){
		s=0;
		double x;
		cin>>x;
		int pos=lower_bound(a,a+n,x)-a;
		if(fabs(a[pos]-x)<1e-6){
			int k=hm[a[pos]];
			s+=qpow(2,n-k)*(qpow(2,k)-1+mod)%mod;
			s%=mod;
			s+=(qpow(2,pos)-1+mod)%mod*((qpow(2,n-pos-k)-1+mod)%mod)%mod;
			s%=mod;
		}else{
			s+=(qpow(2,pos)-1+mod)%mod*((qpow(2,n-pos)-1+mod)%mod)%mod;
			s%=mod;
		}
		cout<<s<<endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; //cin >> t;
	
	while (t --) {
		solve();
	}
	return 0;
}

