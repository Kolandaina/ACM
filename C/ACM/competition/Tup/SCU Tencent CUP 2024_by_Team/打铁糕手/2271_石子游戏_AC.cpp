#include <bits/stdc++.h>

using namespace std;

void solve(){
	
	int n;
	cin >> n;
	if(n > 3 && n % 2 == 0 || n == 1 || n == 3){
		cout << "Alice\n";
	}else {
		cout << "Bob\n";
	}
	
}

int main(){
		
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
		
	return 0;
}
