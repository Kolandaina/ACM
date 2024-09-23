#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=3000013;
const int mod=1e9+7;
ll fc[N],ifc[N],iv[N];
ll c(int x,int y){
	if(x<0||y<0||x<y)return 0;
	return fc[x]*ifc[y]*ifc[x-y];
}
void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	int d=1;
	for(int i=1;i<n;i++)if(s[d]!=s[d-1])d++;
	ll ans=0;
	for(int x=0;x<=a;x++){
		(ans+=c(a+b+d-1,a+a+d-x-1)*c(n-d,x)%mod);
		if(ans>=mod)ans-=mod;
	}
	cout<<ans<<'\n';
}

int main(){
	fc[0]=fc[1]=ifc[0]=ifc[1]=iv[1]=1;
	for(int i=2;i<N;i++)fc[i]=fc[i-1]*i%mod,iv[i]=(mod-mod/i)*iv[mod%i]%mod,ifc[i]=ifc[i-1]*iv[i]%mod;
	ios::sync_with_stdio(false);
	int T=1;
	//cin>>T;
	while(T--)solve();
}
