#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6010;
int n,m1,m2,m3,v[N],w[N],dp[N][3],ans;
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>m1>>m2>>m3;
	for(int i=1;i<=m1+m2+m3;i++)cin>>v[i]>>w[i];
//	for(int i=1;i<=m2;i++)cin>>v2[i]>>w2[i];
//	for(int i=1;i<=m3;i++)cin>>v3[i]>>w2[i];
	for(int i=1;i<=m1+m2+m3;i++){
		for(int z=v[i];z<=n;z++){
			if(i<=m1){
				dp[z][0]=max(dp[z][0],dp[z-v[i]][0]+w[i]);
//				dp[z][1]=max(dp[z][1],dp[z-v[i]][1]);
//				dp[z][2]=max(dp[z][2],dp[z-v[i]][2]);
			}
			else if(i>m1&&i<=m1+m2){
//				dp[z][0]=max(dp[z][0],dp[z-v[i]][0]);
				dp[z][1]=max(dp[z][1],dp[z-v[i]][1]+w[i]);
//				dp[z][2]=max(dp[z][2],dp[z-v[i]][2]);
			}
			else if(i>m1+m2){
				dp[z][2]=max(dp[z][2],dp[z-v[i]][2]+w[i]);
			}
//			cout<<dp[z][0]<<" "<<dp[z][1]<<" "<<dp[z][2]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;i+j<n;j++){
			ans=max(ans,dp[i][0]*dp[j][1]*dp[n-i-j][2]);
//			cout<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}

