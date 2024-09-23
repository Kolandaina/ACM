#include<bits/stdc++.h>
#define LL long long
#define len(G) (LL)(G).size()
#define all(G) (G).begin(),(G).end()
using namespace std;
using ar=array<LL,2>;
using Poly=vector<LL>;

mt19937_64 rnd(random_device{}());

//const LL N=;

const double pi=acos(-1);
LL R,l;

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

int main()
{
	read(R,l);
	if(R==0)
	{
		puts("0");
		return 0;
	}
	double b=1.0*l/R;
	double theta=b/cos(b);
	theta=theta-floor(theta/(2*pi))*2*pi;
	double s=R*theta-l;
	s=abs(s);
	printf("%.15lf\n",min(s,2*pi*R-s));
	return 0;
}
