#include<bits/stdc++.h>
#define LL long long
#define len(G) (LL)(G).size()
#define all(G) (G).begin(),(G).end()
using namespace std;
using ar=array<LL,2>;
using Poly=vector<LL>;

mt19937_64 rnd(random_device{}());

const LL N=2e5+9;

LL n;
LL fa[N];
LL x[N],can[N];
vector<LL> G[N],L;

template<class T>
inline void read(T &x)
{
	x=0;int w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;	c=getchar();}
	while(isdigit(c)){x=x*10+(c-'0');	c=getchar();}
	if(w==-1)	x=-x;
}
template<class T,class... Args>
inline void read(T &x,Args &...args)
{
	read(x),read(args...);
}

template<class T,class U>
inline void chkmin(T &a,U b)
{
	if(b<a)	a=b;
}
template<class T,class U>
inline void chkmax(T &a,U b)
{
	if(b>a)	a=b;
}

void dfs(LL u)
{
	if(x[u])	return;
	LL hc=-1;
	for(LL v:G[u])
	{
		dfs(v);
		if(hc==-1||(x[can[v]]<x[hc]))	hc=can[v];
	}
	
//		printf("%lld %lld\n",u,hc);
	
	can[u]=hc;
	if(u!=1)
		++x[hc];
}

int main()
{
	read(n);
	for(LL i=2;i<=n;++i)
	{
		read(fa[i]);
		G[fa[i]].push_back(i);
	}
	
	for(LL i=1;i<=n;++i)
	{
		if(G[i].empty())
		{
			L.push_back(i);
			can[i]=i;
			x[i]=1;
		}
	}
	dfs(1);
	
	LL minn=(LL)2e9,maxn=-1;
	for(LL u:L)
	{
		chkmin(minn,x[u]);
		chkmax(maxn,x[u]);
	}
	printf("%lld\n",maxn-minn);
	return 0;
}
