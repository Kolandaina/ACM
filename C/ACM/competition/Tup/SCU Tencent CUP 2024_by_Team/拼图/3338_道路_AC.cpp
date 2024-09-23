#include <bits/stdc++.h>
using namespace std;
int n;
const int N=3e5;
vector<int> G[N];
int fa[N];
int dd[N],id[N],dep[N];
void dfs(int x,int dp){
	dep[x]=dp;
	if(G[x].empty()){
		id[x]=x;
		dd[x]=1;
		return;
	}
	dd[x]=N;
	for(int ne:G[x]){
		dfs(ne,dp+1);
		if(dd[ne]<dd[x])dd[x]=dd[ne],id[x]=id[ne];
	}
	dd[x]++;
}
map<int,int> M;
void calc(int x,int tp){
	if(tp!=1)M[dep[tp]-dep[x]]++;
	else{
		M[dep[tp]-dep[x]+1]++;
	}
	while(x!=tp){
		int la=x;
		x=fa[x];
		if(G[x].size()>1){
			for(int ne:G[x]){
				if(ne==la)continue;
				calc(id[ne],ne);
			}
		}
		if(x==tp)break;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		int f;
		cin>>f;
		G[f].push_back(i);
		fa[i]=f;
	}
	dfs(1,1);
	//for(int i=1;i<=n;i++)cout<<id[i]<<' ';
	calc(id[1],1);
	cout << (--M.end())->first - (M.begin())->first << endl;
	return 0;
}

