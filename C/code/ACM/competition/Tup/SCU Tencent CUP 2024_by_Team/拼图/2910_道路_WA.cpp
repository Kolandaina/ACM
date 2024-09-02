#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
vector<int> g[N];
multiset<int> st[N];
int id[N];
void dfs(int u,int fa,int len){
	if(g[u].size()==1){
		dfs(g[u][0],u,len+1);
		id[u] = id[g[u][0]];
	}
	else if(g[u].size()==0){
		st[id[u]].insert(len);
	}
	else{
		for(auto v:g[u]){
			dfs(v,u,1);
			if (st[id[u]].size() < st[id[v]].size()) swap(id[u], id[v]);
			for(auto p:st[id[v]]) st[id[u]].insert(p);
		}
		int x=*(st[id[u]].begin());
		st[id[u]].erase(st[id[u]].begin());
		st[id[u]].insert(x+len);
	}
}
void solve(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		g[x].push_back(i);
	}
	for (int i = 1; i <= n; ++i) id[i] = i;
	dfs(1,0,0);
	cout<<*(--st[id[1]].end())-*(st[id[1]].begin())<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt;
//	cin>>tt;
	tt=1;
	while(tt--){
		solve();
	}
	return 0;
}
/*
6
1 2 2 4 1
*/

