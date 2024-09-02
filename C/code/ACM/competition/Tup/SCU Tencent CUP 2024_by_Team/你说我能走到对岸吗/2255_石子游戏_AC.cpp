#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'

#define ll long long
#define int ll
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int n, m ,k;
void solve(){
	cin >> n;
	if(n < 4){
		if(n == 2){
			cout <<"Bob\n";
		}else{
			cout <<"Alice\n";
		}
	}else{
		if(n&1){
			cout <<"Bob\n";
		}else{
			cout <<"Alice\n";
		}
	}
}
signed main(){
	int _ = 1;
	cin >> _;
	while(_--){
		solve();
	}
	return 0;
}
