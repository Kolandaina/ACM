#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1e5+10;
const long long MOD=1e9+7;
int n, q;
int a[N];
double ss;
long long l, r, m;

long long qpow(long long a, long long x) {
	long long res = 1;
	while (x) {
		if (x & 1) {
			res *= a %= MOD;
		}
		a *= a %= MOD;
		x >>=1;
	}
	return res;
}

int main() {
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;++i){
		scanf("%lf",&ss);
		a[i]=(int)(ss*1000+0.5);
		
	}
	sort(a+1, a+n+1);
	a[0]=-1;a[n+1]=10000000;
	while (q--) {
		l=0,r=n+1;
		int x;
		scanf("%lf",&ss);
		x=(int)(ss*1000+0.5);
		long long L=0,R=n+1,mid;
		while(l<R){
			mid=(l+R)>>1;
			if(a[mid]>=x){
				R=mid-1;
			}
			else l=mid;
			if(l==R-1){
				if(a[R]<x)l=R;
				break;
			}
		}
		while(L<r){
			mid=(L+r)>>1;
			if(a[mid]<=x){
				L=mid+1;
			}
			else r=mid;
			if(L==r-1){
				if(a[L]>x)r=L;
				break;
			}
		}	
		m=r-l-1;r=n-r+1;
		//printf("%lld %lld %lld\n", l, r, m);
		printf("%lld\n", (((qpow(2, l)+MOD-1)%MOD)*((qpow(2,r)+MOD-1)%MOD)%MOD +
								(((qpow(2, m)+MOD-1)%MOD)*(qpow(2,l+r)))%MOD)%MOD);
	}
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

