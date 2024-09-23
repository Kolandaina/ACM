#include <bits/stdc++.h>
using namespace std;
vector<int> P;
const int N = 5e6+100;
bool vis[N];
void solve(int n){
	if(!n) return ;
	int id = lower_bound(P.begin(), P.end(), n+1) - P.begin();
	int l = P[id] - n;
	for(int i = l; i <= n; i++){
		if(i > (n - (i - l))) break;
		printf("%d %d\n", i, n - (i - l));
	}
	solve(l - 1);
}
int main(){
	for(int i = 2; i < N; i++){
		if(!vis[i]){
			for(int j = i; j < N; j += i) vis[j] = true;
			P.push_back(i);
		}
		
	}
	int t;
	scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		n <<= 1;
		solve(n);
	}
	return 0;
}
