#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5,mod=1e9+7;
int n,q;
int w[N];
int p2[N];
inline void work()
{
	scanf("%lld%lld",&n,&q);
	p2[0]=1;
	for(int i=1;i<=n;i++){
		double x;
		scanf("%lf",&x);
		w[i]=x*1000.0;
		p2[i]=p2[i-1]*2%mod;
	}
	sort(w+1,w+n+1);
	for(int i=1;i<=q;i++){
		double x;int po;
		scanf("%lf",&x);
		po=x*1000.0;
		int lmid=lower_bound(w+1,w+n+1,po)-w,rmid=upper_bound(w+1,w+n+1,po)-w-1;
		int mi=lmid-1,ma=n-rmid;
		int	ans=(((p2[n]-1)-(p2[mi]-1)-(p2[ma]-1))%mod+mod)%mod;
		
		ans=(ans+mod)%mod;
		printf("%lld\n",ans);
	}
}
signed main()
{
	work();
	return 0;
}
/*
3 3
10.000
15.000
16.000
00.000
15.000
15.999
*/
