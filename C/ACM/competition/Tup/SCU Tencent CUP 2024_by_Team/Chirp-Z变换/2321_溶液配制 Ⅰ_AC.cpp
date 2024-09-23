#include<bits/stdc++.h>
#define LL long long
#define len(G) (LL)(G).size()
#define all(G) (G).begin(),(G).end()
using namespace std;
using ar=array<LL,2>;
using Poly=vector<LL>;

mt19937_64 rnd(random_device{}());

const LL N=1e5+9,MOD=1e9+7;

LL n,Q;
LL w[N],p2[N];

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

LL add(LL a,LL b,LL p=MOD)
{
	return (a+=b)>=p?a-p:a;
}
LL inc(LL &a,LL b,LL p=MOD)
{
	return a=add(a,b,p);
}
LL sub(LL a,LL b,LL p=MOD)
{
	return (a-=b)<0?a+p:a;
}
LL dec(LL &a,LL b,LL p=MOD)
{
	return a=sub(a,b,p);
}
LL mul(LL a,LL b,LL p=MOD)
{
	return 1LL*a*b%p;
}
LL mult(LL &a,LL b,LL p=MOD)
{
	return a=mul(a,b,p);
}

void init(LL n)
{
	p2[0]=1;
	for(LL i=1;i<=n;++i)
		p2[i]=mul(p2[i-1],2);
}

int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	
	init(N-1);
	
	cin>>n>>Q;
	for(LL i=1;i<=n;++i)
	{
		string s;
		cin>>s;
		s.erase(2,1);
		
		w[i]=stoll(s);
	}
	sort(w+1,w+n+1);
//		for(LL i=1;i<=n;++i)
//			printf("---> %lld\n",w[i]);
	
	while(Q--)
	{
		string s;
		cin>>s;
		s.erase(2,1);
		LL x=stoll(s);
		LL ans=p2[n];
		LL p=upper_bound(w+1,w+n+1,x)-w;
		LL q=lower_bound(w+1,w+n+1,x)-w-1;
		
//			printf("%lld %lld\n",p,q);
		dec(ans,p2[n+1-p]);
		dec(ans,p2[q]);
		inc(ans,1);
//		printf("%lld\n",ans);
		cout<<ans<<"\n";
	}
	
	return 0;
}
