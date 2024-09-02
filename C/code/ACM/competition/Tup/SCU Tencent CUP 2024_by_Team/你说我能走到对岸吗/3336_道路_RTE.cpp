#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'

#define ll long long
#define int ll
const int N = 5e6 + 10;
const int mod = 1e9 + 7;
int siz[N];
int a[N];
vector<int>g[N], du(N);
priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> >pq;
int dfs(int rt, int dep){
	if (a[rt] == 1)return dep;
	dfs(a[rt], dep+1);
}
int vis[N];
int dfs1(int rt, int v){
	if (a[rt] == 1)return v;
	if(vis[rt])return v;
	vis[a[rt]] = 1;
	dfs1(a[rt],v+1);
}
int n;
void solve(){
	cin >> n;
	for(int i = 2;i<=n;i++){
		cin >>a[i];
		du[i]++;
		du[a[i]]++;
	}
	for (int i=2; i<=n; i++){
		if (du[i] == 1){
			pq.push( {dfs(i, 1), i});
		}
	}
	int mi = 1e17;
	int mx = 0;
	while(!pq.empty()){
		pair<int,int> it = pq.top();
		pq.pop();
		int now = dfs1(it.second,1);
		mi = min(mi,now);
		mx = max(mx,now);
		//cout << now << ' ' << it.second << endl;
	}
	cout << mx - mi <<endl;
}
/*
6
RR'
F2B2
UUU
LDL'D'
R2F'UR'U2R2F'R'U2U'R2U'F2U'R'FR2U'R'URU'R'FU
*/
signed main(){
	int _ = 1;
	//cin >> _;
	for (int i = 1; i <= _; i++){
		solve();
	}
	return 0;
}
