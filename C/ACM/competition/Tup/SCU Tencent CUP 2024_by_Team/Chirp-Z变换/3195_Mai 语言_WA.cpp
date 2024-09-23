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

int main()
{
	read(n,m,K);
	if(m<4)
	{
		puts("-1");
		return 0;
	}
	
//	while(1)
//	{
//		printf("n=%lld, K=%lld\n",n,K);
//		
//		if(K<n)
//		{
//			LL t=1;
//			for(;;++t)
//				if(K>=ce(n,1<<t))
//				{
//					break;
//				}
//			LL x=1<<t,lx=len(to_string(x));
//			
//			if(lx+3>m)
//			{
//				puts("-1");
//				return 0;
//			}
//			
//			for(LL i=1;i<=x;++i)
//			{
//				ans.push_back({x,1});
//			}
//			
//			--K;
//			n-=x;
//		}
//		else
//		{
//			if(n*(m-4)>=K-n)
//			{
//				LL tot=K-n;
//				for(LL i=1;i<=n;++i)
//				{
//					LL cnt=min(tot,m-4);
//					tot-=cnt;
//					ans.push_back({1,cnt+1});
////					out(1,cnt+1);
//				}
//				break;
//			}
//			else
//			{
//				puts("-1");
//				return 0;
//			}
//		}
//	}
//	
//	for(ar p:ans)
//	{
//		LL x=p[0],cnt=p[1];
//		out(x,cnt);
//	}
	
	if(K>=n)
	{
		if(n*(m-4)>=K-n)
		{
			LL tot=K-n;
			for(LL i=1;i<=n;++i)
			{
				LL cnt=min(tot,m-4);
				tot-=cnt;
				out(1,cnt+1);
			}
		}
		else
		{
			puts("-1");
		}
		return 0;
	}
//	
//	for(LL )
//	{
//		
//	}
	
	if(m==4)
	{
		for(LL c1=0;c1<=n;++c1)
			for(LL c2=0;c2<=n;++c2)
				for(LL c4=0;c4<=n;++c4)
					for(LL c8=0;c8<=n;++c8)
					{
						if(c1+c2+c4+c8==n&&c8+2*c4+4*c2+8*c1==8*K)
						{
							for(LL i=1;i<=c1;++i)
								out(1,1);
							for(LL i=1;i<=c2;++i)
								out(2,1);
							for(LL i=1;i<=c4;++i)
								out(4,1);
							for(LL i=1;i<=c8;++i)
								out(8,1);
							
							return 0;
						}
					}
		puts("-1");
		return 0;
	}
	
	for(LL i=1;i<=K-1;++i)
	{
		out(1,1);
	}
	n-=(K-1);
	
	LL h=__lg(n),m=1<<h;
	if(m<n)	m*=2;
	
	for(LL i=1;i<=m-n;++i)
		out(m/2,1);
	
	for(LL i=1;i<=n-(m-n);++i)
		out(m,1);
	
	return 0;
}
