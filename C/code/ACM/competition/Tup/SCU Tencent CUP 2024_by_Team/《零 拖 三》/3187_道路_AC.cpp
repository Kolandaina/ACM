#include <bits/stdc++.h>

using namespace std;

int read(){
	int res=0,sign=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')sign=-sign;
	for(;'0'<=ch&&ch<='9';ch=getchar()){
		res=(res<<3)+(res<<1)+(ch^'0');
	}
	return res*sign;
}

#define rep(i,l,r) for(int i=l;l<=r;++i)
#define dep(i,r,l) for(int i=r;i>=l;--i)

const int N=2e5+10;

int n;
int fa[N];

vector<int> G[N];

int d[N];

struct leaf_t{
	int u,dep;
	bool operator<(const leaf_t& o)const{
		return dep<o.dep;
	}
};

vector<leaf_t> lf;

void dfs(int u,int dep){
	d[u]=dep;
	if(G[u].size()==0){
		lf.push_back({u,dep});
	}
	for(int v:G[u]){
		dfs(v,dep+1);
	}
}

int vis[N],cnt[N],idx;

int main(){
	n=read();
	for(int i=2;i<=n;++i){
		fa[i]=read();
		G[fa[i]].push_back(i);	
	}
	dfs(1,0);
	sort(lf.begin(),lf.end());
	
//	for(auto l:lf){
//		cout<<l.u<<' ';
//	}puts("");
	
	vis[1]=-1;
	for(auto&& l:lf){
		int u=l.u;
//		cout<<u<<'\n';
		++idx;
		while(!vis[u]){
			vis[u]=idx;
			++cnt[idx];
			u=fa[u];
		}
	}
	int mx=-1,mn=n+1;
	for(int i=1;i<=idx;++i){
		if(cnt[i]>mx)mx=cnt[i];
		if(cnt[i]<mn)mn=cnt[i];
	}
	cout<<mx-mn<<'\n';
//	for(int i=1;i<=n;++i)cout<<vis[i]<<'\n';
	return 0;
}

/*
12
1 2 3 4 2 6 6 1 9 10 9
*/
