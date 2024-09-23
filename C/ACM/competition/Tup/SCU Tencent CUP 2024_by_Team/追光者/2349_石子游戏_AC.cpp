#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int a[N];
void pre(){
	for(int i = 1; i <= 1e6; i++){
		if(i & 1){
			if(a[i - 1] == 0) a[i] = 1;
		}
		else {
			if(a[i - 1] == 0 || a[i >> 1] == 0) a[i] = 1;
		}
	}
}
void solve(){
	int n;
	cin >> n;
	if(a[n])cout << "Alice\n";
	else cout << "Bob\n";
}
signed main(){
	int T;
	cin >> T;
	pre();
	while(T--){
		solve();
	}	
	return 0;
}
