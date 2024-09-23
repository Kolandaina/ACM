#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e4+10;
int	v1[p],v2[p],v3[p],w1[p],w2[p],w3[p],dp1[p],dp2[p],dp3[p];
int ans1[20009];
int ans2[20009];


signed main(){
	
	int n,m1,m2,m3;
	cin>>n;
	cin>>m1>>m2>>m3;
	for(int i=1;i<=m1;i++){
		cin>>v1[i]>>w1[i];
	}
	for(int i=1;i<=m2;i++){
		cin>>v2[i]>>w2[i];
	}
	for(int i=1;i<=m3;i++){
		cin>>v3[i]>>w3[i];
	}
	for(int i=1;i<=m1;i++){
		for(int j=n;j>=v1[i];j--){
			dp1[j]=max(dp1[j-v1[i]]+w1[i],dp1[j]);
		}
	}
	for(int i=1;i<=m2;i++){
		for(int j=n;j>=v2[i];j--){
			dp2[j]=max(dp2[j-v2[i]]+w2[i],dp2[j]);
		}
	}
	for(int i=1;i<=m3;i++){
		for(int j=n;j>=v3[i];j--){
			dp3[j]=max(dp3[j-v3[i]]+w3[i],dp3[j]);
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<":"<<dp1[i]<<' '<<dp2[i]<<' '<<dp3[i]<<endl;
//	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
		{
			ans1[i+j]=max(ans1[i+j],dp1[i]*dp2[j]);
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
		  ans2[i+j]=max(ans2[i+j],ans1[i]*dp3[j]);	
		}
	}
	printf("%lld\n",ans2[n]);
     return 0;
    
}
