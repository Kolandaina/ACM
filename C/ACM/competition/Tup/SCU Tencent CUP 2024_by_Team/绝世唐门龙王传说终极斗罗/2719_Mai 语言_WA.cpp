#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
#define rep(i, l, r) for(ll i = (l); i <= (r); ++i)
#define rep_(i, l, r) for(ll i = (l); i >= (r); --i)
#define endl '\n'
const ll N = 20 +7, P = 1e9 + 7, INF = 1e18;
ll cnt[N];
void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	if(n == 1) {
		if(k > m) cout << -1 << endl;
		else {
			cout << "{1}";
			rep(i,1,m) cout << ",";
			cout << endl;
		}
		return;
	}
	if(m == 1) {
		cout << -1 << endl;
		return;
	}
	if(k == 1){
		rep(i ,1, n) {
			if(i != n) {
				cout << "{" << (ll)pow(2,i) << "}," << endl;
			}
			else {
				cout << "{" << (ll)pow(2,i) << "},," << endl;
			}
		}
		return;
	}
	k -= 2;
	rep(i,1,n) cnt[i] = 1;
	cnt[n] = 2;
	rep(i, 1, n) {
		ll num = min(k,m - cnt[i]);
		k -= num; cnt[i] += num;
		if(k == 0) break;
		k *= 2;
	}
	if(k != 0) {
		cout << -1 << endl;
		return;
	}
	rep(i, 1, n) {
		cout << "{" << (ll)pow(2,i - 1) << "}";
		rep(j, 1, cnt[i]) cout << ",";
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T(1); 
	//cin >> T;
	while (T--) solve();
	return 0;
}
