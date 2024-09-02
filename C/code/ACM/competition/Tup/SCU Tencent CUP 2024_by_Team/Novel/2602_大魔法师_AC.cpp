#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[3][2005],minn[3],ans,n,m[3],v,w;

signed main()
{
	memset(minn,0x3f3f3f3f,sizeof(minn));
	cin>>n;
	cin>>m[0]>>m[1]>>m[2];
	for(int i = 0;i<3;i++){
		for(int j = 0;j<m[i];j++){
			cin>>v>>w;
			minn[i] = min(minn[i],v);
			for(int k = n;k>=v;k--) dp[i][k] = max(dp[i][k],dp[i][k-v]+w);
		}
	}
	for(int i = minn[0];i<=n;i++){
		for(int j = minn[1];j+i<=n;j++){
			ans = max(ans,dp[0][i]*dp[1][j]*dp[2][n-i-j]);
		}
	}
	cout<<ans;
	return 0;
}
