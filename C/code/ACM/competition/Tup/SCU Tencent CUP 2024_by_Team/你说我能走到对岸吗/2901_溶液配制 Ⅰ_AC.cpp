#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'

#define ll long long
#define int ll
const int mod = 1e9 + 7;
int kmi (int n, int m)
{
	int res = 1;
	while (m)
	{
		if (m & 1)res = res * n % mod;
		n = n * n % mod;
		m >>= 1;
	}
	return res;
}
void solve(){
	int n, q;
	cin >> n >> q;
	vector<double> a1(n);
	for (auto &i : a1)cin >> i;
	sort(a1.begin(), a1.end());
	double x;
	int k = kmi(2, n) - 1;
	while (q--)
	{
		cin >> x;
		if(a1[0] > x || a1[n - 1]<x){
			cout << 0 <<endl;
			continue;
		}
		int ans = k;
		int id;
		if(a1[0] < x){
		    id = lower_bound(a1.begin(), a1.end(), x) - a1.begin();
			if (id != 0){
				//if (a1[id] == x)id--;
				ans = ans - kmi(2, id) + 1;
				ans = (ans + mod) % mod;
			}
		}
		if(a1[n - 1] > x){
			id = upper_bound(a1.begin(), a1.end(), x) - a1.begin();
			ans = ans - kmi(2, (n - id)) + 1;
			ans = (ans + mod) % mod;
		}
		cout << (ans + mod) % mod << endl;
	}
}

signed main(){
	int _ = 1;
	//cin >> _;
	for(int i = 1;i<=_;i++){
		solve();
	}
	return 0;
}
