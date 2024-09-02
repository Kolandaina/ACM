#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5,mod=1e9+7;
int n,q;
double w[N];
int p2[N];
inline int getl(double x)
{
	int l = 1, r = n, k = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(w[mid] < x) l = mid + 1, k = mid;
		else r = mid - 1;
	}
	return k;
}
inline int getr(double x)
{
	int l = 1, r = n, k = n + 1;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(w[mid] > x) r = mid - 1, k = mid;
		else l = mid + 1;
	}
	return k;
}
void work()
{
	scanf("%lld%lld", &n, &q);
	p2[0] = 1;
	for(int i = 1;i <= n;i ++){
		double x;
		scanf("%lf", &w[i]);
		p2[i] = 1ll * p2[i - 1] * 2 % mod;
	}
	sort(w + 1, w + n + 1);
	for(int i = 1;i <= q;i ++){
		double x;
		scanf("%lf", &x);
		int lmid = getl(x), rmid = getr(x);
		int mi = lmid, ma = n - rmid + 1;
//		if(mi == 0 || ma == 0)
//		{
//			puts("0");
//			continue;
//		}
		long long ans = (p2[n] - 1 - p2[mi] + 1 - p2[ma] + 1) % mod;
		ans = (ans + mod) % mod;
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
