#include<bits/stdc++.h> 
using namespace std;
#define int long long
const long long mod=1000000007;
int node(int x,int y){
	int ret=1;
	while(y)
	{
		if(y%2) ret=ret*x%mod;
		y/=2;
		x=x*x%mod;
	}
	return ret;
}
signed main(){
	int n,ans;
    cin>>n;
	ans=(node(2,n)%mod)*((node(2,n)+1)%mod);
	ans=ans/2%mod;
	cout<<ans;
	return 0;
}