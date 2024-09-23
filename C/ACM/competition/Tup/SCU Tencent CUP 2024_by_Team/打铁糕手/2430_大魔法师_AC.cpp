#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e3 + 10;
int v1[N],v2[N],v3[N],w1[N],w2[N],w3[N];

/*
10 2 2 2
2 1
3 2
2 1
3 2
5 3
4 2

10 3 3 1
4 5
2 3
3 4
6 8
2 4
4 3
4 2
*/

signed main(){
		
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m1,m2,m3;
	cin >> n >> m1 >> m2 >> m3;

	for(int i = 1;i <= m1;i ++){
		cin >> v1[i] >> w1[i];
	}
	for(int i = 1;i <= m2;i ++){
		cin >> v2[i] >> w2[i];
	}
	for(int i = 1;i <= m3;i ++){
		cin >> v3[i] >> w3[i];
	}
	
	vector<int> dp1(N),dp2(N),dp3(N);
	
	for(int i = 1;i<=m1;i++)
		for(int j = n;j>=v1[i];j--)
			dp1[j] = max(dp1[j],dp1[j-v1[i]]+w1[i]);
			
	for(int i = 1;i<=m2;i++)
		for(int j = n;j>=v2[i];j--)
			dp2[j] = max(dp2[j],dp2[j-v2[i]]+w2[i]);	
			
	for(int i = 1;i<=m3;i++)
		for(int j = n;j>=v3[i];j--)
			dp3[j] = max(dp3[j],dp3[j-v3[i]]+w3[i]);
	
	
	int ans = 0;
	for(int i = 1;i<=n-2;i++){
		for(int j = 1;j<=n-i-1;j++){
			int k = n - i - j;
//			cout << i << ' ' << j << ' ' << k << '\n' ;
			int x = dp1[i] * dp2[j] * dp3[k];
			ans = max(ans, x);
//			if(x > ans){
//				cout << dp1[i] << ' ' << dp2[j] << ' ' << dp3[k] << '\n';
//			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
