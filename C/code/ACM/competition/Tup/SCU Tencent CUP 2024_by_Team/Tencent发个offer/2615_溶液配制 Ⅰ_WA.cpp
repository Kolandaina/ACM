#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,Mod=1e9+7;
double v[N];
int pw(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%Mod;
		(a*=a)%=Mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>v[i];
	sort(v+1,v+n+1);
	for(int i=0;i<q;i++){
		double t;
		int ans;
		cin>>t;
		int x=lower_bound(v+1,v+n+1,t)-v,l,r;
//		cout<<x<<endl;
		if(v[x]==t){
			l=x-1,r=n-x;
//			cout<<l<<" "<<r<<endl;
//			cout<<n-1<<" "<<pw(2,n-1)<<endl;
			ans=((pw(2,l)-1)*(pw(2,r)-1)%Mod+pw(2,n-1))%Mod;
		}else{
			l=x-1,r=n-x+1;
//			cout<<l<<" "<<r<<endl;
			ans=(pw(2,l)-1)*(pw(2,r)-1)%Mod;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
//3 3
//10.000
//15.000
//16.000
//00.000
//15.000
//15.999
