#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
//int n,m;
int n;
vector<int> e[N];
int p[N];
int maxn=0,minn=N;
int dfs1(int u){
	if(e[u].size()==0)
		return 1;
	if(e[u].size()==1){
		return dfs1(e[u][0])+1;
	}
	priority_queue<pair<int,int> >q;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		q.push({-dfs1(v),v});
	}
	pair<int,int> t = q.top();q.pop();
	p[u]=t.second;
	t.first--;
	return -t.first;
}
void dfs2(int u,int cnt){
	if(e[u].size()==0){
		//cout<<u<<" "<<cnt<<endl;
		maxn=max(maxn,cnt+1);
		minn=min(minn,cnt+1);
		return;
	}
	if(e[u].size()==1){
		if(u==1)
			dfs2(e[u][0],cnt);
		else
			dfs2(e[u][0],cnt+1);
		return;
	}
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(p[u]==v){
			if(u==1)
			dfs2(v,cnt);
			else
			dfs2(v,cnt+1);
		}else{
			dfs2(v,0);
		}
	}

}
void sovle(){
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return;
	}
	for(int i=2;i<=n;i++){
		int t;
		cin>>t;
		e[t].push_back(i);
	}
	dfs1(1);
	dfs2(1,0);
//	cout<<p[1]<<endl;
//	cout<<p[2]<<endl;
//	cout<<dfs1(1)-1<<endl;
//	cout<<dfs2(1)<<endl;
	//cout<<maxn<<endl;
	cout<<maxn-minn<<endl;
}
int main(){
	sovle();
}
