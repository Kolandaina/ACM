#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int a[N][2],cnt;
int f;
int b[N << 1]; //b[i] = 0: noprime
void pre(){
	b[1] = 1;
	for(int i = 2; i * i <= 2e6; i++){
		if(b[i]== 1) continue;
		for(int j = i + i; j <= 2e6; j += i)
			b[j] = 1;
	}
	/*for(int i = 1; i <= 100; i++){
		if(!b[i]) cout << i << ' ';
	}*/
}
void dfs(int i, int j){
	//cout << "this:" << i << ' ' << j << endl;
	if(!j) return;
	while(b[i + j]) {
		if(i > j) {
			f = 1;
			return;
		}
		i += 2;
	}
	for(int k = i; k <= j; k += 2){
		cnt++;
		a[cnt][1] = k;
		a[cnt][0] = j + i - k;
		//cout << k << ' ' << j + i - k << '\n';
	}
	dfs(1, i - 1);
}
int T;
void solve(){
	int n = T;
	f = 0;
	cnt = 0;
	cin >> n;
	dfs(1, (n << 1));
	if(f){
		cout << "-1\n";
		return ;
	}
	for(int i = 1; i <= n; i++){
		cout << a[i][1] << ' ' << a[i][0] << '\n';
	}
}
signed main(){
	
	pre();
	cin >> T;
	
	while(T--){
		solve();
	}	
	return 0;
}
