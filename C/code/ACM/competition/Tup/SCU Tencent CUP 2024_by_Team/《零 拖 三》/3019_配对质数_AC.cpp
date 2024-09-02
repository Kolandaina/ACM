#include <bits/stdc++.h>

using namespace std;

int read(){
	int res=0,sign=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')sign=-sign;
	for(;'0'<=ch&&ch<='9';ch=getchar()){
		res=(res<<3)+(res<<1)+(ch^'0');
	}
	return res*sign;
}

#define rep(i,l,r) for(int i=l;l<=r;++i)
#define dep(i,r,l) for(int i=r;i>=l;--i)

const int N=2e6+10;

int prime[N],vis[N],idx;

void init(){
	for(int i=2;i<N;++i){
		if(!vis[i])prime[++idx]=i;
		for(int j=1;j<=idx;++j){
			int p=prime[j];
			if(1ll*p*i>=N)break;
			vis[i*p]=1;
			if(i%p==0)break;
		}
	}
}

int qpow(int a, int b,int mod) {
	int res=1,base=a%mod;
	for(;b;b>>=1,base=1ll*base*base%mod)if(b&1){
		res=(1ll*res*base)%mod;
	}
	return res%mod;
}

int MR(int p){
	if(p<2)return 0;
	if(p==2)return 1;
	if(p==3)return 1;
	int d=p-1,r=0;
	while(!(d&1))d>>=1,++r;
	for(int k=1;k<=10;++k){
		int a=rand()%(p-2)+2;
		int x=qpow(a,d,p);
		if(x==1||x==p-1)continue;
		for(int i=1;i<=r-1;++i){
			x=1ll*x*x%p;
			if(x==p-1)break;
		}
		if(x!=p-1)return 0;
	}
	return 1;
}

int n;

void solve(){
	n=read();
	for(int i=1;i<=idx;++i){
		int p=prime[i],q=p+2*n;
		if(MR(q)){
			for(int j=1;j<=p/2;++j){
				cout<<j<<' '<<p-j<<'\n';
			}
			for(int j=p;j<=p/2+n;++j){
				cout<<j<<' '<<p+2*n-j<<'\n';
			}
			return;
		}
	}
	puts("-1");
}

int main(){
	srand((unsigned)time(nullptr));
	init();
	int t=read();
	while(t--)solve();
//	for(int i=1;i<=20;++i)solve(i),puts("");
	return 0;
}
