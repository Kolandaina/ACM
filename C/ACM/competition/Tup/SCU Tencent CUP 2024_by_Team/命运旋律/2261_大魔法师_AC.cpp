#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
void solve(){
	int n,m1,m2,m3;
	cin>>n>>m1>>m2>>m3;
	vi dp1(n+10,0),dp2(n+10,0),dp3(n+10,0);
	for(int i=1;i<=m1;i++){
		int x,y;
		cin>>x>>y;
		for(int j=n;j>=x;j--){
			dp1[j]=max(dp1[j],dp1[j-x]+y);
		}
	}
	for(int j=1;j<=m2;j++){
		int x,y;
		cin>>x>>y;
		for(int j=n;j>=x;j--){
			dp2[j]=max(dp2[j],dp2[j-x]+y);
		}
	}
	for(int i=1;i<=m3;i++){
		int x,y;
		cin>>x>>y;
		for(int j=n;j>=x;j--){
			dp3[j]=max(dp3[j],dp3[j-x]+y);
		}
	}
	int ans=0,cnt=0;
	for(int i=0;i<=n;i++){
		for(int j=0;i+j<=n;j++){
			int k=n-i-j;
			if(dp1[i]&&dp2[j]&&dp3[k]){
				ans=max(ans,dp1[i]*dp2[j]*dp3[k]);
			}
		}
	}
//	cout<<cnt<<endl;
	cout<<ans<<endl;
}
signed main(){
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
