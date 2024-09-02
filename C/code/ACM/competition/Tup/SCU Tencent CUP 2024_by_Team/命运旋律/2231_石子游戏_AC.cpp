#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
int dp[1000100];
void solve(){
	int n ;
	cin >> n;
	if(!dp[n]%2) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}
signed main(){
	int _=1;
	cin>>_;
    dp[1]=1,dp[2]=0;
	for(int i=3;i<=1000000;i++){
		if(i%2==0) dp[i] =  1 - min(dp[i-1],dp[i/2]);
		else dp[i] =  1- dp[i-1];
	}
	while(_--) solve();
	return 0;
}
