#include <bits/stdc++.h>
#define N 100005
#define M 1000000007
using namespace std;

long long int qmi(int m, int k, int p)
{
	long long int res=1%p, t=m;
	while(k)
	{
		if(k&1) res=res*t%p;
		t=t*t%p;
		k>>=1;
	}	
	return res%p;
}

double v[N];
int main()
{
	int n, q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%lf",&v[i]);
	sort(v,v+n);
	int mini, maxi;
	while(q--)
	{
		double x;
		scanf("%lf",&x);
		int mini=lower_bound(v,v+n,x)-v;
		int maxi=n-(upper_bound(v,v+n,x)-v);
		int equal=n-mini-maxi;
		long long int ans=(((qmi(2,mini,M)-1)*(qmi(2,maxi,M)-1)))%M;
		if(equal)
			ans+=(qmi(2,mini+maxi,M))%M;
		printf("%lld\n",ans%M);
	}
}
