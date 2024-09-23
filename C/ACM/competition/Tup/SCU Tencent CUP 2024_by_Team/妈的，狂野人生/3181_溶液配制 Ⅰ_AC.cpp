#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e6+10,mod=1e9+7;
double w[p];

int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b=b>>1;
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	sort(w+1,w+1+n);
	double x;
	for(int i=1;i<=m;i++){
		cin>>x;
		int k1=lower_bound(w+1,w+1+n,x)-w;
		int k2=upper_bound(w+1,w+1+n,x)-w;
		int a=k1-1,b=k2-k1,c=n-k2+1;
		int ans=((ksm(2,b)-1)*(ksm(2,a+c))+(ksm(2,a)-1)*(ksm(2,c)-1))%mod;
		cout<<ans<<endl;		
	}

	return 0;
    
}
