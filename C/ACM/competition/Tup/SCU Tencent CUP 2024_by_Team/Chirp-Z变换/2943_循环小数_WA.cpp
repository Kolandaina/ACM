#include<bits/stdc++.h>
#define LL long long
#define len(G) (LL)(G).size()
#define all(G) (G).begin(),(G).end()
using namespace std;
using ar=array<LL,2>;
using Poly=vector<LL>;

mt19937_64 rnd(random_device{}());

//const LL N=;

LL a,s,b,t;

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

LL qpow(LL a,LL b)
{
	LL x=a,ans=1;
	while(b)
	{
		if(b&1)	ans*=x;
		x*=x;
		b>>=1;
	}
	return ans;
}

void solve()
{
	read(a,s,b,t);
	LL n=qpow(a,s)-1,m=qpow(b,t)-1;
	LL g=__gcd(n,m);
	if(g==1)
	{
		puts("-1");
		return;
	}
	printf("%lld %lld\n",1LL,g);
}

int main()
{
	LL T;
	read(T);
	while(T--)	solve();
	return 0;
}
