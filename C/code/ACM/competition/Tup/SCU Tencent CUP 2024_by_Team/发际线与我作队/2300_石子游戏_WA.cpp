#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005

int dp[maxn];

void sovle(){
	int t, n;
	cin >> t;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 0;
	for(int i = 3; i < maxn; ++i) {
		if(i % 2)
			dp[i] = !dp[i-1];
		else
			dp[i] = !(dp[i-1] || dp[i - i/2]);
	}
	for(int i = 0; i < t; ++i) {
		cin >> n;
		if(dp[n])
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;
	}
}
int main(){
	sovle();
}
