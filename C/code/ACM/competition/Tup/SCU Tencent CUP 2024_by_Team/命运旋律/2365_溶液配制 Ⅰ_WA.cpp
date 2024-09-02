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
	double a[100010];
	map<double,int> mp;
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i = 1; i<=m;i++){
		double x;
		cin >> x;
		if(mp[x]){
			int l = 0, r= n;
			while(r>l){
				int mid = l+r >> 1;
				if(a[mid] > x) r = mid;
				else l = mid+1;
			}
//			cout << l << endl;
			if(l==n&&a[n] < x){
				cout << 0 << endl;
			}
			else cout << ((qmi(2,l-mp[x]-1) - 1)*((n-l+2)*(n-l+1)/2%mod) %mod + (qmi(2,l-mp[x]-1)) * (qmi(2,n-l+1))%mod * (qmi(2,mp[x])-1))%mod << endl;
		}
		else {
			int l = 0, r= n;
			while(r>l){
				int mid = l+r >> 1;
				if(a[mid] > x) r = mid;
				else l = mid+1;
			}
//			cout << l << endl;
			if(l==n&&a[n] < x){
				cout << 0 << endl;
			}
			else cout << (qmi(2,l-1) - 1)*((n-l+2)*(n-l+1)/2%mod)%mod << endl;
		}
	}
}
signed main(){
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
