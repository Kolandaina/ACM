#include<bits/stdc++.h>
using namespace std;
int n,siz[200005],son[200005],now[200005],val[200005],mi,mx;
vector<int>vec[200005];
void dfs2(int u,int pre)
{
	now[u]=now[son[u]];
	if(siz[u]==1)
	{
		val[u]=0;
	}
	val[u]=-1;
	for(int i=0;i<vec[u].size();++i)
	{
		dfs2(vec[u][i],u);
		if(val[u]==-1||val[vec[u][i]]<val[u])
		{
			if(val[u]!=-1)mx=max(mx,val[u]),mi=min(mi,val[u]);
			val[u]=val[vec[u][i]];
		}
		else 
		{
			mx=max(mx,val[vec[u][i]]);
			mi=min(mi,val[vec[u][i]]);
		}
	}
	if(u!=1)val[u]++;
}
int main()
{
	scanf("%d",&n);
	mi=n+1,mx=0;
	for(int i=2;i<=n;++i)
	{
		int x;scanf("%d",&x);
		vec[x].push_back(i);
	}
	dfs2(1,0);
	mx=max(mx,val[1]);
	mi=min(mi,val[1]);
	cout<<mx-mi<<endl;
}
