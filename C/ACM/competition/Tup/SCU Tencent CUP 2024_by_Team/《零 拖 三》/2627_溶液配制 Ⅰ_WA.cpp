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

const int mod=1e9+7;

int qpow(int a, int b) {
	int res=1,base=a%mod;
	for(;b;b>>=1,base=1ll*base*base%mod)if(b&1){
		res=(1ll*res*base)%mod;
	}
	return res%mod;
}

const int N=1e5+10;

int n,q;
double a[N];

void solve() {
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	
	sort(a+1,a+1+n);
	
	while(q--){
		double x;cin>>x;
		int pos=lower_bound(a+1,a+n+1,x)-a;
		
//		cout<<pos<<'\n';
		
		if(abs(a[pos]-x)<5e-4){
			int i=pos;
			int ans=(1ll*qpow(2,n)-qpow(2,i-1)-qpow(2,n-i)+1)%mod;
			printf("%d\n",ans);
		}else{
//			puts("yyy");
			int i=pos-1;
			int ans=((1ll*qpow(2,i)-1) * (1ll*qpow(2,n-i)-1))%mod;
			printf("%d\n",ans);
		}
	}
}
int main(){
	int t = 1;
	while (t--) solve();	
	return 0;
}

/*
3 3
10.000
15.000
16.000
00.000
15.000
15.999

*/
