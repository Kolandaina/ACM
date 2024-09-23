#include<bits/stdc++.h>
#define LL long long
#define len(G) (LL)(G).size()
#define all(G) (G).begin(),(G).end()
using namespace std;
using ar=array<LL,2>;
using Poly=vector<LL>;

mt19937_64 rnd(random_device{}());

//const LL N=;

Poly a(24);

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
	read(x).read(args...);
}

void tr(Poly G)
{
	Poly tmp(len(G));
	for(LL i=0;i<len(G)-1;++i)
	{
		tmp[i+1]=a[G[i]];
	}
	tmp[0]=a[G.back()];
	for(LL i=0;i<len(G);++i)
		a[G[i]]=tmp[i];
}

void R()
{
	tr({20,21,23,22});
	tr({7,3,15,11});
	tr({5,1,13,9});
}
void L()
{
	tr({16,17,19,18});
	tr({0,4,8,12});
	tr({2,6,10,14});
}
void F()
{
	tr({4,5,7,6});
	tr({2,20,9,19});
	tr({3,22,8,17});
}
void B()
{
	tr({12,13,15,14});
	tr({0,18,11,21});
	tr({1,16,10,23});
}
void U()
{
	tr({0,1,3,2});
	tr({4,16,15,20});
	tr({5,17,14,21});
}
void D()
{
	tr({8,9,11,10});
	tr({6,22,13,18});
	tr({7,23,12,19});
}

void R2()
{
	R(),R();
}
void L2()
{
	L(),L();
}
void F2()
{
	F(),F();
}
void B2()
{
	B(),B();
}
void U2()
{
	U(),U();
}
void D2()
{
	D(),D();
}

void r()
{
	for(LL j=1;j<=3;++j)
		R();
}
void l()
{
	for(LL j=1;j<=3;++j)
		L();
}
void f()
{
	for(LL j=1;j<=3;++j)
		F();
}
void b()
{
	for(LL j=1;j<=3;++j)
		B();
}
void u()
{
	for(LL j=1;j<=3;++j)
		U();
}
void d()
{
	for(LL j=1;j<=3;++j)
		D();
}

void solve()
{
	for(LL i=0;i<24;i+=4)
		for(LL j=i;j<i+4;++j)
			a[j]=i/4;
	
	string s;
	cin>>s;
	for(LL i=0;i<len(s);++i)
	{
		char c=s[i];
		if(i+1<len(s)&&!isalpha(s[i+1]))
		{
			if(s[i+1]=='2')
			{
				if(c=='R')	R2();
				if(c=='L')	L2();
				if(c=='F')	F2();
				if(c=='B')	B2();
				if(c=='U')	U2();
				if(c=='D')	D2();
			}
			else
			{
				if(c=='R')	r();
				if(c=='L')	l();
				if(c=='F')	f();
				if(c=='B')	b();
				if(c=='U')	u();
				if(c=='D')	d();
			}
			++i;
		}
		else
		{
			if(c=='R')	R();
			if(c=='L')	L();
			if(c=='F')	F();
			if(c=='B')	B();
			if(c=='U')	U();
			if(c=='D')	D();
		}
	}
	
	for(LL i=0;i<24;i+=4)
	{
		for(LL j=i;j<i+4;++j)
		{
			if(a[j]!=a[i])
			{
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	LL T;
	cin>>T;
	while(T--)	solve();
	return 0;
}
