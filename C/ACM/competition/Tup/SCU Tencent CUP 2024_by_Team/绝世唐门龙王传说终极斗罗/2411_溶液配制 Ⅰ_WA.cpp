#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;


#define rep(i, l, r) for(ll i = (l); i <= (r); ++i)
#define rep_(i, l, r) for(ll i = (l); i >= (r); --i)
#define endl '\n'
const ll N = 1e6 +7, P = 1e9 + 7, INF = 1e18;
bool f[N];
ll n;
long long w[100001];
ll qpow(ll x,ll p) {
	ll ans = 1;
	while(p) {
		if(p & 1) ans = ans * x % P;
		x = x * x % P;
		p >>= 1;
	}
	return ans;
}
void solve() {
	int n,q;
	cin>>n>>q;
	double s;
	for(int i=1;i<=n;++i){
		cin>>s;
		w[i] = (ll)(s * 1000);
	}
	sort(w+1,w+n+1);
	long long p;
	while(q--){
		cin>>s;
		p=(long long)(s*1000);
		if(p > w[n] || p < w[1]) {
			cout << 0 << endl;
			continue;
		}
		ll pos = lower_bound(w + 1, w + n + 1, p) - w;
		if(w[pos] == p){
			ll r = upper_bound(w + 1,w +n + 1,p) - w - 1;
			ll ans = (qpow(2,n) - qpow(2,pos - 1) - qpow(2, n - r) + 1) % P;
			ans =(ans + P)%P;
			cout << ans << endl;
		}
		else {
			ll ans = (qpow(2,n) - qpow(2,n - pos + 1) - qpow(2, pos - 1) + 1) % P;
			ans =(ans + P)%P;
			cout << ans << endl;
		}
	}

}
/*
void init() {
	int n=2e6+5;
	for(int i=2;i<=n;++i){
		if(!vis[i]){
			g.push_back(i);
		}
		for(auto &j:g){
			if(j*i>n)break;
			vis[i*j]=1;
			if(i%j==0)break;
		}
	}
}
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T(1); 
	//init();
	//cin >> T;
	while (T--) solve();
	return 0;
}
