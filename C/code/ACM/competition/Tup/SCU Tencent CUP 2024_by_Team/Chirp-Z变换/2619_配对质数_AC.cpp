#include<bits/stdc++.h>
#define LL long long
#define len(G) (LL)(G).size()
#define all(G) (G).begin(),(G).end()
using namespace std;
using ar=array<LL,2>;
using Poly=vector<LL>;

mt19937_64 rnd(random_device{}());

const LL N=3e6+9;

LL n;
LL nx[N];
bitset<N> vis;

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

void solve()
{
	read(n);
	LL u=2*n;
	while(u)
	{
		LL x=nx[u]-u;
		for(LL i=x,j=u;i<j;++i,--j)
			printf("%lld %lld\n",i,j);
		u=x-1;
	}
}

bool isp(LL x)
{
	return x>=2&&!vis[x];
}

void init(LL n)
{
	for(LL i=2;i<=n;++i)
	{
		if(!vis[i])
		{
			for(LL j=i*i;j<=n;j+=i)
				vis[j]=1;
		}
	}
	LL cp=0;
	for(LL i=(LL)2e6;;++i)
		if(isp(i))
		{
			cp=i;
			break;
		}
	
	for(LL i=(LL)2e6;i>=1;--i)
	{
		nx[i]=cp;
		if(isp(i))	cp=i;
	}
}

int main()
{
	init((LL)2.2e6);
	
	LL T;
	read(T);
	while(T--)	solve();
	return 0;
}
