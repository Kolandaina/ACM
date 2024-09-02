#include <bits/stdc++.h>

#define int long long

using namespace std;

/*

*/

vector<bool> f(int n){
	vector<int> pr;
	vector<bool> is(n + 1,1);
	is[1] = 0;
	for(int i = 2;i <= n;i ++){
		if(is[i]) pr.push_back(i);
		for(int j = 0;j < pr.size() && i * pr[j] <= n;j ++){
			is[i * pr[j]] = 0;
			if(i % pr[j] == 0) break;
		}
	}
	return is;
}

const int N = 4e6 + 10;

auto is = f(N);

void solve(){
	
	int n;
	cin >> n;
	if(is[2 * n + 1]){
		for(int i = 1;i < 2 * n + 1 - i;i ++){
			cout << i << ' ' << 2 * n + 1 - i << '\n';
		}
		return ;
	}else{
		for(int i = 1;i<n;i++){
			int a = 2 * i + 1;
			if(is[a] && is[a + 2 * n]){
				for(int j = 1;j < a - j;j ++)
					cout << j << ' ' << a - j << '\n';
				for(int j = a;j < 2 * n - j + a;j ++)
					cout << j << ' ' << 2 * n - j + a << '\n';
				return ;
			}
		}
		cout << -1 << '\n';
		return ;
	}
	
}

signed main(){
		
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
	
	return 0;
}
