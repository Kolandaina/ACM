#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int r=0,f=1;char  c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return r*f;
}
inline string sread(){
	string s=" ";char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while(c<='z'&&c>='a')s+=c,c=getchar();
	return s;
}
int lowbit(int x){return x&(-x);}

long double pi=3.141592653;

signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	long double x,r; cin>>r>>x;
	long double st=x/r;
	long double phi=x/(r*cos(st));
	long double a=phi-st;
	while(a>2*pi) a-=2*pi;
	if(a>pi) a=2*pi-a;
	long double ans=r*a;
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}

