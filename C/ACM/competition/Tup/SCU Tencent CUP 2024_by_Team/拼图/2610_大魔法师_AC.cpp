#include <bits/stdc++.h>
#define LL long long
#define int long long
#define pii pair<long long,long long>
using namespace std;
LL n,m[3];
void calc(vector<int>& dp,vector<pii>& A){
	dp.resize(n+1);
	fill(dp.begin(),dp.end(),0);
	for(auto& p:A){
		for(int h=n;h>=p.first;h--){
			dp[h]=max(dp[h],dp[h-p.first]+p.second);
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m[0]>>m[1]>>m[2];
	vector<vector<int>> dp(3,vector<int>());
	vector<vector<pii>> A(3,vector<pii>());
	for(int i=0;i<3;i++){
		A[i].resize(m[i]);
		for(int j=0;j<m[i];j++){
			auto &tp=A[i][j];
			cin>>tp.first>>tp.second;
		}
	}
	for(int i=0;i<3;i++)calc(dp[i],A[i]);
	LL ans=0;
	for(LL x=1;x<=n-2;x++)for(LL y=1;x+y<=n-1;y++){
		ans=max(ans,dp[0][x]*dp[1][y]*dp[2][n-x-y]);
	}
	cout<<ans;
	return 0;
}
/*10 2 2 2 
2 1
3 2
2 1
3 2
5 3
4 2
*/

