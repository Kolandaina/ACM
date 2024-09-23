#include<bits/stdc++.h>
using namespace std;

struct Node{
	int ch,d;
}node[200005];
int n,x,minn = 0x3f3f3f3f,maxn,d[200005],len;
bool vis[200005];
vector<int> v[200005];
vector<int> v0[200005];
queue<int> q;
bool cmp(Node a,Node b){return a.d<b.d;}

void dfs(int a,int cnt){
	for(int i = 0;i<v[a].size();i++){
		d[v[a][i]] = cnt;
		dfs(v[a][i],cnt+1);
	}
}

void dfs1(int a,int cnt){
	if(v0[a].size()==0){
		minn = min(minn,cnt);
		maxn = max(maxn,cnt);
	}
	else{
		for(int i = 0;i<v0[a].size();i++){
			if(vis[v0[a][i]]) dfs1(v0[a][i],cnt);
			else{
				vis[v0[a][i]] = true;
				dfs1(v0[a][i],cnt+1);
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i = 2;i<=n;i++){
		cin>>x;
		v[x].push_back(i);
		v0[i].push_back(x);
	}
	for(int i = 2;i<=n;i++){
		if(v[i].size()==0) q.push(i);
	}
	dfs(1,2);
	while(!q.empty()){
		x = q.front();
		q.pop();
		node[++len].ch = x;
		node[len].d = d[x];
	}
	sort(node+1,node+1+len,cmp);
	vis[1] = true;
	for(int i = 1;i<=len;i++){
		vis[node[i].ch] = true;
		dfs1(node[i].ch,1);
	}
	cout<<maxn-minn;
	return 0;
}
