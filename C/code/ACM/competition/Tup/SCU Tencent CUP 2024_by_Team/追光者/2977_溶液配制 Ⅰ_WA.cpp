#include<bits/stdc++.h>
#define int long long
#define eps 1e-6
using namespace std;

const int mod=1e9+7;
int n,q;
double a[100005];

int quick_pow(int a,int b,int p)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%p;
		a=a*a%p;
		b/=2;
	}
	return res;
}

signed main(){

	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+n+1);
	
	while(q--)
	{
		double ta;
		cin>>ta;
		
		if(ta<a[1] || ta>a[n])
		{
			cout<<0<<endl;
			continue;
		}
		
		int l=1,r=n;
		while(l<r)
		{
			int mid=l+r>>1;
			if(a[mid]>=ta)r=mid;
			else l=mid+1;
		}
		
		if(a[l]==ta)
		{
			int t=(quick_pow(2,l-1,mod)-1)*(quick_pow(2,n-l,mod)-1)%mod;
			cout<<(t+quick_pow(2,n-1,mod))%mod<<endl;
		}
		else
		{
			cout<<(quick_pow(2,l-1,mod)-1)*(quick_pow(2,n-l+1,mod)-1)%mod<<endl;
		}
	}
	
	return 0;
}
