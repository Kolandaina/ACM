#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

double a[100005];
int t[100];
map<double,int>hm;

int qpow(int x,int n){
	int ans=1;
	while(n){
		if(n&1){
			ans*=x;
			//ans%=mod;
		}
		x*=x;
		//x%=mod;
		n>>=1;
	}
	return ans;
}

void solve() {
	int n,m,k;
	cin>>n>>m>>k;
	k*=qpow(2,n-1);
	int s=0;
	for(int i=0;i<n;i++){
		s+=qpow(2,n-1-i)*(m-3-(int)log10(qpow(2,i)));
		t[i]=m-3-(int)log10(qpow(2,i));
	}
	if(s>=k){
		for(int i=0;i<n;i++){
			//cout<<s<<' '<<k<<endl;
			if(s-(t[i]-1)*qpow(2,n-1-i)>=k){
				s-=(t[i]-1)*qpow(2,n-1-i);
				t[i]=1;
			}else if(s>k){
				int l=(s-k)/qpow(2,n-1-i);
				s-=l*qpow(2,n-1-i);
				t[i]-=l;
			}
			if(s<=k)break;
		}
		if(s==k){
			for(int i=0;i<n;i++){
				cout<<'{'<<qpow(2,i)<<'}';
				for(int j=0;j<t[i];j++){
					cout<<',';
				}cout<<endl;
			}
		}else{
			cout<<-1;
		}
		//cout<<s<<' '<<k<<endl;
	}else{
		cout<<-1<<endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; //cin >> t;
	
	while (t --) {
		solve();
	}
	return 0;
}

