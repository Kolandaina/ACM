#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
const int mod = 1e9 + 7;
int qmi(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
void solve(){
	int x,r;
	cin >> r >> x;
	double ans;
//	cout << cos(1.0/3*3.14);
	if(r==0){
		cout<<0;
		return;
	}
	ans = x*1.0*((1.0/(cos(x*1.0/(r))) - 1)); 
	printf("%.10lf",ans);
}
signed main(){
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
