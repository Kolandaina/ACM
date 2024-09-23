#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
vector<int> g[N];
multiset<int> st[N];
int id[N];
void dfs(int u){
	if (g[u].size() == 1) {
		st[id[u]].insert(1);
		return;
	}
	for(auto v:g[u]){
		dfs(v);
		if (st[id[u]].size() < st[id[v]].size()) swap(id[u], id[v]);
		for(auto p:st[id[v]]) st[id[u]].insert(p);
	}
	int x=*(st[id[u]].begin());
	st[id[u]].erase(st[id[u]].begin());
	st[id[u]].insert(x+1);
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
	dfs(1);
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
5
1 1 3 4
7
1 2 3 3 5 6
5
1 1 1 1
6
1 2 3 4 4
*/

