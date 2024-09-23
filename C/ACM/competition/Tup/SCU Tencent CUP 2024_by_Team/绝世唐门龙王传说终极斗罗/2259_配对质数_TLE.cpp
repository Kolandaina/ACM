#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;


#define rep(i, l, r) for(ll i = (l); i <= (r); ++i)
#define rep_(i, l, r) for(ll i = (l); i >= (r); --i)
const ll N = 1e6 +7, P = 1e9 + 7, INF = 1e18;
bool f[N];
ll n;
vector<int>g;
int vis[4000001];
void solve() {
	cin>>n;
	n=2*n;
	while(n){
		int q=upper_bound(g.begin(),g.end(),n)-g.begin();
		int z=g[q]-n;
		int y=n;
		while(z<y){
			cout<<z<<' '<<y<<endl;
			z++;
			y--;
		}
		n=g[q]-n-1;
	}

}

void init() {
	int n=4e6;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T(1); 
	init();
	cin >> T;
	while (T--) solve();
	return 0;
}
