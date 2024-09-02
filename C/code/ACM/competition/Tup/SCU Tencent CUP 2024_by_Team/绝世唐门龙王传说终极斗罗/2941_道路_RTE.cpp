#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
#define rep(i, l, r) for(ll i = (l); i <= (r); ++i)
#define rep_(i, l, r) for(ll i = (l); i >= (r); --i)
#define endl '\n'
//const ll N = 20 +7, P = 1e9 + 7, INF = 1e18;
vector<int>g[200001];
int son[200001];
//int vis[200001];
int qs[200001];//qing er zi
int dfs1(int u,int v){
	son[u]=1;
	for(auto &j:g[u]){
		son[u]+=dfs1(j,u);
		if(son[j]<son[qs[u]]){
			qs[u]=j;
		}
	}
}
int maxn=0,minn=2e5+1;
void dfs2(int u,int v,int x){
	if(u!=1)x=x+1;
	if(qs[u]==0){
		maxn=max(maxn,x);
		minn=min(minn,x);
		return;
	}
	dfs2(qs[u],u,x);
	for(auto &j:g[u]){
		if(j==qs[u])continue;
		dfs2(j,u,0);
	}
}
void solve() {
	int n;
	cin>>n;
	son[0]=2e5+10;
	int v;
	for(int i=2;i<=n;++i){
		cin>>v;
		g[v].push_back(i);
	}
	dfs1(1,0);
	dfs2(1,0,0);
	cout<<maxn-minn<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T(1); 
	//cin >> T;
	while (T--) solve();
	return 0;
}

