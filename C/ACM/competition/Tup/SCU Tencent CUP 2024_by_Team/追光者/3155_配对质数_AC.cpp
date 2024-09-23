#include<bits/stdc++.h>
#define int long long
#define ot(x, y) cout << x << ' ' << y << '\n';
using namespace std;
const int N = 1e6 + 1000;
int a[N][2] , cnt;
int f;
int b[N << 1]; //b[i] = 0: noprime

int primes[N],idx;
bool st[N << 2];
void pre(){
	st[1]=true;
	for(int i=2;i<=4e6;i++)
	{
		if(!st[i])primes[idx++]=i;
		for(int j = 0;i*primes[j]<=4e6;j++)
		{
			st[i*primes[j]]=true;
			if(i%primes[j]==0)break;
		}
	}
	//for(int i = 1999999; i <= 2000100; i++)
	//	if(!st[i]) cout << i << ' ';
}
void dfs(int i, int j){
	//cout << "this:" << i << ' ' << j << endl;
	if(!j) return;
	while(st[i + j]) {
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
		//ot(k, j + i - k);
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
	//cout << cnt << ' ';
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
