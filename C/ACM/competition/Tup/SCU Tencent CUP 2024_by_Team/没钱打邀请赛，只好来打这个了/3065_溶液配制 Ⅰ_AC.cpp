#include<bits/stdc++.h>
using namespace std;
const int N=100005;
double w[N];

using ll = long long;
ll mod=(1e9)+7;
ll qpow(ll x,ll n ){
	ll res=1;
	while(n>0){
		if(n&1)res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

map<double,ll> mp;
int main(){
	int n,q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>w[i];
		mp[w[i]]++;
	}
	sort(w+1,w+1+n);
	while(q--){
		double x;
		cin>>x;
		if(x<w[1]){
			cout<<"0\n";
			continue;
		}
		auto a=lower_bound(w+1,w+1+n,x)-w-1;
		auto b=upper_bound(w+1,w+1+n,x)-w;
		b=n-b+1;
		//cout<<pos<<" "<<pos1<<"\n";
		//cout<<w[pos]<<"\n";
		long long res=0;
		ll ans=1;
		res=(qpow(2ll,a)-1)*(qpow(2ll,b)%mod-1)%mod;
		ll c=mp[x];
		//cout<<c<<"\n";
		if(c==0)mp.erase(x);
		res+=(qpow(2ll,c)-1)*qpow(2ll,a+b)%mod;
		res%=mod;
		cout<<res<<"\n";
	}
	return 0;
}
