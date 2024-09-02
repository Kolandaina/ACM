#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;


#define rep(i, l, r) for(ll i = (l); i <= (r); ++i)
#define rep_(i, l, r) for(ll i = (l); i >= (r); --i)
const ll N = 1e6 +7, P = 1e9 + 7, INF = 1e18;
bool f[N], vis[N];
ll n;

void solve() {
	cin>>n;
	if(f[n]) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

void init() {
	f[1] = true;
	f[2] = false;
	rep(i,3,1e6) { 
		if(i & 1){
			f[i] = f[i - 1] ^ 1;
		}
		else {
			f[i] = !(f[i - 1] && f[i / 2]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T(1); 
	init();
	cin >> T;
	while (T--) solve();
	return 0;
}
