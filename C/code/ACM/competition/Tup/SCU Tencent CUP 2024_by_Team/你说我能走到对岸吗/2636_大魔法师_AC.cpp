#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'

#define ll long long
#define int ll
const int N = 5e6 + 10;
const int mod = 1e9 + 7;
const double pi = 3.14159265358979323846264;
void solve(){
	int n, m1, m2, m3;
	cin >> n >> m1 >> m2 >> m3;
	vector<int> dp1(n + 1);
	int a, b;
	for (int i=0; i<m1; i++){
		cin >> a >> b;
		for (int j=n; j>=a; j--){
			if (j - a == 0 || dp1[j-a]){
				dp1[j] = max(dp1[j], dp1[j-a] + b);
			}
		}
	}
	vector<int> dp2(n + 1);
	for (int i=0; i<m2; i++){
		cin >> a >> b;
		for (int j=n; j>=a; j--){
			if (j - a == 0 || dp2[j-a]){
				dp2[j] = max(dp2[j], dp2[j-a] + b);
			}
		}
	}
	vector<int> dp3(n + 1);
	for (int i=0; i<m3; i++){
		cin >> a >> b;
		for (int j=n; j>=a; j--){
			if (j - a == 0 || dp3[j-a]){
				dp3[j] = max(dp3[j], dp3[j-a] + b);
			}
		}
	}
	vector<int> dp4(n + 1);
	for (int i=0; i<=n; i++){
		for (int j=0; i + j <= n; j++){
			if (dp1[i] && dp2[j])dp4[i + j] = max(dp4[i + j], dp1[i] * dp2[j]);
		}
	}
	int ans = 0;
	for (int i=0; i<=n; i++){
		for (int j=0; i + j <= n; j++){
			if (dp4[i] && dp3[j])ans = max(ans, dp4[i] * dp3[j]);
		}
	}
	cout << ans <<  endl;
}
signed main(){
	int _ = 1;
	//cin >> _;
	for(int i = 1;i<=_;i++){
		solve();
	}
	return 0;
}
