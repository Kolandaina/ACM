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
typedef double db;
typedef long long ll;
const int N = 1e5+100;
const int mod = 1e9+7;
ll qpow(ll x, int y){
	if(y < 0) return 0;
	ll ans = 1;
	while(y){
		if(y&1) ans = ans * x% mod;
		x = x*x %mod, y>>=1;
	}
	return ans;
}

int n, q;
double w[N];
ll solve(db now);
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%lf", &w[i]);
	sort(w+1, w+n+1);
	
	while(q--){
		db now; scanf("%lf", &now);
		printf("%lld\n", solve(now));
	}
	return 0;
}
ll solve(db now){
	ll l = lower_bound(w+1, w+n+1, now) - w;
	ll r = upper_bound(w+1, w+n+1, now) - w - 1;
	ll ans = 0;
	if(l <= r){
		int cnt = r - l + 1;
		ans = (ans + (qpow(2, cnt) - 1 )* qpow(2, l-1) % mod * qpow(2, n-r) % mod) % mod;
	}
	ans = (ans + (qpow(2, l-1) - 1) * (qpow(2, n-r)-1) % mod + mod) % mod;
	ans = (ans%mod + mod) % mod;
	return ans;
}
