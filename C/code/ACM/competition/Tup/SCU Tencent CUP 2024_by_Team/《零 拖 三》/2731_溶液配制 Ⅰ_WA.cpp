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
int b[N];

int d[N];

void modify(int x,int c){
	for(;x<N;x+=x&-x){
		d[x]+=c;
	}
}

int query(int x){
	int res=0;
	for(;x;x-=x&-x){
		res+=d[x];
	}
	return res;
}

void solve() {
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)b[i]=a[i]*1000;
	
//	for(int i=1;i<=n;++i)cout<<b[i]<<'\n';
	
//	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		modify(b[i],1);
	
	while(q--){
		double x;cin>>x;
		int _x=x*1000;
//		int pos=lower_bound(a+1,a+n+1,x)-a;
		
//		cout<<pos<<'\n';
		
//		if(abs(a[pos]-x)<5e-4){
//			int i=pos;
//			int ans=((1ll*qpow(2,n)-qpow(2,i-1)-qpow(2,n-i)+1)%mod+mod)%mod;
//			printf("%d\n",ans);
//		}else{
////			puts("yyy");
//			int i=pos-1;
//			int ans=(((1ll*qpow(2,i)-1) * (1ll*qpow(2,n-i)-1))%mod+mod)%mod;
//			printf("%d\n",ans);
//		}
		int cnt1=_x==0?0:query(_x-1);
		int cnt2=query(100010)-query(_x);
		int cnt3=query(_x)-cnt1;
		int ans=1ll*(qpow(2,cnt1)-1)*(qpow(2,cnt2)-1)%mod+
			(1ll*(qpow(2,cnt3)-1)*qpow(2,cnt1+cnt2)%mod);
		ans=ans%mod;
		cout<<ans<<'\n';
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

/*
5 99
10 20 30 40 50
9.999
19.999
30.001
49.999
50.001
30.000
40.000

*/

/*
5 99
10 20 20 20 50
9.999
19.999
30.001
49.999
50.001
30.000
40.000

*/

/*
35 99
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
21 22 23 24 25 26 27 28 29 30
31 32 33 34 35

*/
