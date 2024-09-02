#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
#define rep(i, l, r) for(ll i = (l); i <= (r); ++i)
#define rep_(i, l, r) for(ll i = (l); i >= (r); --i)
#define endl '\n'
const ll N = 2e3 +7, P = 1e9 + 7, INF = 1e18;
const ld pi = 3.1415926535;

void solve() {
	int r, x;
	cin >> r >> x;
	cout << (ld(1) / (ld)cos((ld)x / (ld)r) - 1) * ld(x) << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int T(1); 
	//cin >> T;
	while (T--) solve();
	return 0;
}
