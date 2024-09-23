#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,inf=0x3f3f3f3f;
int n,m,fa[N],dep[N],minn=inf,maxx,dp[N];
vector<int>vt[N];
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	for(auto v:vt[x]){
		dfs(v);
	}
	if(!vt[x].size()){
		dp[x]=1;
	}
}
void dfs2(int x){
	int mxl=-inf,mil=inf;
	for(auto v:vt[x]){
		dfs2(v);
		mil=min(mil,dp[v]);
		mxl=max(mxl,dp[v]);
//		cout<<"---"<<dp[v]<<endl;
	}
//	cout<<dp[x]<<" "<<mxl<<" "<<mil<<endl;
	if(vt[x].size()){
		dp[x]=mil+1;
		maxx=max(maxx,mxl);
		minn=min(minn,mxl);
	}
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2,f;i<=n;i++){
		cin>>f;
		vt[f].push_back(i);
		fa[i]=f;
	}
	dfs(1);
	dfs2(1);
//	cout<<dp[1]<<" "<<maxx<<" "<<minn<<endl;
	cout<<max(dp[1],maxx)-min(dp[1],minn);
	return 0;
}

