#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
//int n,m;
int n;
vector<int> e[N];
int maxn,minn;
int dfs1(int u){
	if(e[u].size()==0)
		return 1;
	if(e[u].size()==1){
		return dfs1(e[u][0])+1;
	}

	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		q.push(dfs1(v));
	}
	int t=q.top()+1;q.pop();
	q.push(t);
	return q.top();
}
int dfs2(int u){
	if(e[u].size()==0)
		return 1;
	if(e[u].size()==1){
		if(u==1) return dfs2(e[u][0]);
		return dfs2(e[u][0])+1;
	}
	priority_queue<int,vector<int>,less<int> >q;
	priority_queue<int,vector<int>,greater<int> >p;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		int t=dfs2(v);
		q.push(t);
		p.push(t);
	}
	int t=p.top()+1;
	q.push(t);
	return q.top();
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
	minn=dfs1(1)-1;
	maxn=dfs2(1);
//	cout<<dfs1(1)-1<<endl;
//	cout<<dfs2(1)<<endl;
	cout<<maxn-minn<<endl;
}
int main(){
	sovle();
}
