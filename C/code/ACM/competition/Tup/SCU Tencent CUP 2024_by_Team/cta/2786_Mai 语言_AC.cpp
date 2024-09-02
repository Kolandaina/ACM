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

int const N=35;
int num[N];

inline int len(int x){
	long long a=1ll<<(x-1);
	int ans=0;
	while(a){
		a/=10;
		ans++;
	}
	return ans+2;
}

signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,m,k; n=read(),m=read(),k=read();
	if(k==1&&n==1){
		if(m<4){
			puts("-1");
			return 0;
		}
		puts("{1},");
		return 0;
	}
	if(k==1) n++;
	num[1]=k;
	int now=1;
	while(true){
		int lnow=len(now);
		if(lnow>m){
			puts("-1");
			return 0;
		}
		int l=num[now]+lnow;
		if(l>m){
			num[now+1]+=(l-m)*2;
			num[now]-=l-m;
		}
		else break;
		if(now>=n){
			puts("-1");
			return 0;
		}
		now++;
	}
	while(now<n){
		num[now+1]=2,num[now]--;
		now++;
	}
	if(num[now]+len(now)>m){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=now;++i){
		if(!num[i]) continue;
		int x=1<<(i-1);
		cout<<"{"<<x<<"}";
		for(int j=1;j<=num[i];++j){
			cout<<",";
		}puts("");
	}
	return 0;
}

