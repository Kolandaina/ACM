#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2003;
const int mod=1e9+7;
int m[3];
ll dp[3][N];
ll f[N],g[N];
void solve(){
	int n;
	cin>>n;
	for(int o=0;o<3;o++){
		cin>>m[o];}
	for(int o=0;o<3;o++){
		for(ll i=1,y,x;i<=m[o];i++){
			cin>>x>>y;
			for(int i=n;i>=x;i--){
				dp[o][i]=max(dp[o][i],dp[o][i-x]+y);
			}
		}
	}
	for(int i=0;i<=n;i++)for(int j=0;i+j<=n;j++)f[i+j]=max(dp[0][i]*dp[1][j],f[i+j]);
	for(int i=0;i<=n;i++)for(int j=0;i+j<=n;j++)g[i+j]=max(dp[2][i]*f[j],g[i+j]);
	cout<<*max_element(g+1,g+n+1)<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	int T=1;
	cout<<fixed<<setprecision(15);
	//cin>>T;
	while(T--)solve();
}
