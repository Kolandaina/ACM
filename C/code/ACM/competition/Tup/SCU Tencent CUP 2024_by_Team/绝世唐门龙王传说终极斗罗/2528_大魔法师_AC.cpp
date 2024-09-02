#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
#define rep(i, l, r) for(ll i = (l); i <= (r); ++i)
#define rep_(i, l, r) for(ll i = (l); i >= (r); --i)
#define endl '\n'
const ll N = 2e3 +7, P = 1e9 + 7, INF = 1e18;
long long dp1[N],dp2[N],dp3[N];

void solve() {
	int n;
	cin>>n;
	int m1,m2,m3;
	cin>>m1>>m2>>m3;
	long long v,w;
	for(int i=1;i<=m1;++i){
		cin>>v>>w;
		if(v>n)continue;
		//dp1[v]=max(dp1[v],w);
		for(int j=n-v;j>=0;--j){
			if(j+v>n)break;
			dp1[v+j]=max(dp1[j]+w,dp1[v+j]);
			
		}
	}
	for(int i=1;i<=m2;++i){
		cin>>v>>w;
		if(v>n)continue;
		//dp2[v]=max(dp2[v],w);
		for(int j=n-v;j>=0;--j){
			if(j+v>n)break;
			dp2[v+j]=max(dp2[j]+w,dp2[v+j]);
			
		}
	}
	for(int i=1;i<=m3;++i){
		cin>>v>>w;
		if(v>n)continue;
		//dp3[v]=max(dp3[v],w);
		for(int j=n-v;j>=0;--j){
			if(j+v>n)break;
			dp3[v+j]=max(dp3[j]+w,dp3[v+j]);
			
		}
	}
	long long ans=0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n-i;++j){
			int k=n-i-j;
			ans=max(ans,dp1[i]*dp2[j]*dp3[k]);
		}
	}
	cout<<ans<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T(1); 
	//cin >> T;
	while (T--) solve();
	return 0;
}
