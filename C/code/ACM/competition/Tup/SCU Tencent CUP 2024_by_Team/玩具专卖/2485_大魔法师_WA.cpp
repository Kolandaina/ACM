#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3+5,mod=1e9+7;
int n,ma,mb,mc;
int a[N],b[N],c[N],sc[N];
inline void work()
{
	scanf("%lld%lld%lld%lld",&n,&ma,&mb,&mc);
	for(int i=1;i<=ma;i++){
		int v,w;scanf("%lld%lld",&v,&w);
		for(int j=n;j>=1;j--){
			if(j>=v) a[j]=max(a[j],a[j-v]+w);
		}
	}
	for(int i=1;i<=mb;i++){
		int v,w;scanf("%lld%lld",&v,&w);
		for(int j=n;j>=1;j--){
			if(j>=v) b[j]=max(b[j],b[j-v]+w);
		}
	}
	for(int i=1;i<=mc;i++){
		int v,w;scanf("%lld%lld",&v,&w);
		for(int j=n;j>=1;j--){
			if(j>=v) c[j]=max(c[j],c[j-v]+w);
		}
	}
	for(int i=1;i<=n;i++){
		sc[i]=max(c[i],sc[i-1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,a[i]*b[j]*sc[n-i-j]);
		}
	}
	printf("%lld\n",ans);
}
signed main()
{
	work();
	return 0;
}
/*
10 2 2 2
2 1
3 2
2 1
3 2
5 3
4 2
*/
