#include<bits/stdc++.h>
using namespace std;
int n,m,tot;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int nows[1000005],nowt[1000005],head[2000005],cnt,valmi[1000005],valmx[1000005],belong[1000005],low[1000005],dfn[1000005],idx,vis[1000005],dian,dmi[1000005],dmx[1000005],in[1000005];
stack<int>st;
vector<int>vec[1000005];
struct edge{int to,next,from;
}e[5000005];
void add(int x,int y)
{
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt++;
}
void build(int l,int r,int rt)
{
	if(l==r){nows[rt]=l;nowt[rt]=l;valmi[l]=valmx[l]=l;return ;}
	int mid=(l+r)>>1;
	nows[rt]=(++tot);
	nowt[rt]=(++tot);
	build(lson);build(rson);
	add(nows[rt<<1],nows[rt]);
	add(nows[rt<<1|1],nows[rt]);
	add(nowt[rt],nowt[rt<<1]);
	add(nowt[rt],nowt[rt<<1|1]);
}
void update(int L,int R,int l,int r,int rt,int flag)
{
	if(L<=l&&R>=r)
	{
		if(flag==0)
		{
		    add(nows[rt],tot);
		}
		else 
		{
			add(tot,nowt[rt]);
		}
		return ;
	}
	int mid=(l+r)>>1;
	if(L<=mid)update(L,R,lson,flag);
	if(R>mid)update(L,R,rson,flag);
}
void tarjan(int u)
{
	dfn[u]=low[u]=++idx;
	st.push(u);
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		if(!dfn[e[i].to])tarjan(e[i].to);
		if(vis[e[i].to])low[u]=min(low[u],low[e[i].to]);
	}
	if(dfn[u]==low[u])
	{
		dian++;
		dmi[dian]=n+1;dmx[dian]=-1;
		while(1)
		{
			int v=st.top();
			st.pop();
			vis[v]=0;
			belong[v]=dian;
			dmi[dian]=min(dmi[dian],valmi[v]);
			dmx[dian]=max(dmx[dian],valmx[v]);
			if(u==v)break;
		}
	}
}
queue<int>q;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		idx=0;
		cnt=1;
	    scanf("%d%d",&n,&m);
	    tot=n;
	    for(int i=1;i<=9*n+m;++i)head[i]=0,valmi[i]=n+1,valmx[i]=-1,vec[i].clear(),in[i]=0,belong[i]=0,in[i]=0,dmi[i]=n+1,dmx[i]=-1,nows[i]=nowt[i]=0,low[i]=0,dfn[i]=0,vis[i]=0;
	    build(1,n,1);
	    dian=0;
	    for(int i=1;i<=m;++i)
	    {
	    	int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
	    	tot++;
	    	update(a,b,1,n,1,0);
	    	update(c,d,1,n,1,1);
		}
		for(int i=1;i<=tot;++i)
		if(!belong[i])tarjan(i);
		for(int i=1;i<cnt;++i)
		{
			if(belong[e[i].from]!=belong[e[i].to])
			{
				vec[belong[e[i].to]].push_back(belong[e[i].from]);
				in[belong[e[i].from]]++;
			}
		}
		for(int i=1;i<=dian;++i)
		{
			if(!in[i])
			{
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=0;i<vec[u].size();++i)
			{
				int v=vec[u][i];
				in[v]--;
				dmx[v]=max(dmx[v],dmx[u]);
				dmi[v]=min(dmi[v],dmi[u]);
				if(!in[v])q.push(v);
			}
		}
		for(int i=1;i<=n;++i)
		{
			printf("%d %d\n",dmi[belong[i]],dmx[belong[i]]);
		}
    }
}
