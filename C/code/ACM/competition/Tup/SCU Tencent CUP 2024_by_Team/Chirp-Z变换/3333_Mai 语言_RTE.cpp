#include<bits/stdc++.h>
#define LL long long
#define len(G) (LL)(G).size()
#define all(G) (G).begin(),(G).end()
using namespace std;
using ar=array<LL,2>;
using Poly=vector<LL>;

mt19937_64 rnd(random_device{}());

//const LL N=;

LL n,m,K;
LL lim[990],t[909];
bool f[19][11<<10];
vector<ar> ans;

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

void out(LL x,LL cnt)
{
	printf("{");
	printf("%lld",x);
	printf("}");
	for(LL i=1;i<=cnt;++i)
		printf(",");
	puts("");
}

LL ce(LL a,LL b)
{
	return (a+b-1)/b;
}

//void dfs(LL k)
//{
//	if(k>n)
//	{
//		
//		return;
//	}
//	
//}

LL d(LL S,LL i)
{
	return S>>i&1;
}

LL le(LL x)
{
	return len(to_string(x));
}

void dfs(LL i,LL k)
{
	if(i==0)	return;
	for(LL j=1;j<=lim[i];++j)
	{
		LL st=k-(j<<(t[n]-t[i]));
		if(k-(j<<(t[n]-t[i]))>=0 && f[i-1][k-(j<<(t[n]-t[i]))])
		{
			
			out(1<<t[i],j);
//				puts("*******");
			
			dfs(i-1,st);
			return;
		}
	}
}

int main()
{
	read(n,m,K);
	if(m<4||n>=8)
	{
		puts("-1");
		return 0;
	}
//	if(n>=)
	
	for(LL S=0;S<(1<<8);++S)
	{
		if(__builtin_popcountll(S)==n)
		{
			LL cnt=0;
			for(LL i=0;i<=9;++i)
			{
				if(d(S,i))
				{
					t[cnt++]=i;
				}
			}
			bool ok=1;
			for(LL i=1;i<=n;++i)
			{
				lim[i]=m-2-le(1<<t[i]);
				if(lim[i]<1)
				{
					ok=0;
//					puts("-1");
//					return 0;
				}
			}
			if(ok==0)	continue;
			
			LL y=K<<t[n];
			
			memset(f,0,sizeof(f));
			f[0][0]=1;
			for(LL i=1;i<=n;++i)
			{
				for(LL k=0;k<=y;++k)
				{
					for(LL j=1;j<=lim[i];++j)
					{
						if(k-(j<<(t[n]-t[i]))>=0)
							f[i][k]|=f[i-1][k-(j<<(t[n]-t[i]))];
					}
				}
			}
			
			
//			if(f[n][y]==0)
//			{
//				puts("-1");
//				return 0;
//			}
			if(f[n][y])
			{
				dfs(n,y);
				exit(0);
			}
			
		}
	}
	
	
	puts("-1");
//		puts("*******");
	
	return 0;
}
