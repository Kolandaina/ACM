#include<bits/stdc++.h>
#define LL long long
#define len(G) (LL)(G).size()
#define all(G) (G).begin(),(G).end()
using namespace std;
using ar=array<LL,2>;
using Poly=vector<LL>;

mt19937_64 rnd(random_device{}());

const LL N=2009;

LL n;
LL m[4];
LL f[4][N];

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
inline void chkmax(T &a,U b)
{
	if(b>a)	a=b;
}

int main()
{
	read(n);
	for(LL k=1;k<=3;++k)
		read(m[k]);
	for(LL k=1;k<=3;++k)
	{
		for(LL i=1;i<=m[k];++i)
		{
			LL v,w;
			read(v,w);
			for(LL j=n;j>=v;--j)
				chkmax(f[k][j],f[k][j-v]+w);
		}
	}
	LL ans=0;
	for(LL a=0;a<=n;++a)
		for(LL b=0;a+b<=n;++b)
		{
			LL c=n-a-b;
			chkmax(ans,f[1][a]*f[2][b]*f[3][c]);
		}
	printf("%lld\n",ans);
	return 0;
}
