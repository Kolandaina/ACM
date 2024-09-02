#include<bits/stdc++.h>
#define int __int128
using namespace std;
int T,LG,a,s,b,t;
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
void put(int x){if(x>9)put(x/10);putchar(x%10+'0');}
int qpow(int x,int y){int s=1;for(;y;y>>=1,x=x*x)if(y&1)s=s*x;return s;}
int lowbit(int x){return x&(-x);}
int gcd(int x,int y){
	if(!y)return x;
	return gcd(y,x%y);
}
int ggcd(int x,int y){
	if(x>y)return gcd(x,y);
	return gcd(y,x);
}
int lcm(int x,int y){return x/ggcd(x,y)*y;}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read(),LG=qpow(2,63);
	while(T--){
		a=read(),s=read(),b=read(),t=read();
		if(s>a||t>b){puts("-1");continue;}
		int x=qpow(a,s)-1,y=qpow(b,t)-1;
		int LCM=lcm(x,y);
		if(LCM>=LG){puts("-1");continue;}
		put(LCM/x+LCM/y),printf(" ");
		put(LCM),puts("");
	}
	return 0;
}
