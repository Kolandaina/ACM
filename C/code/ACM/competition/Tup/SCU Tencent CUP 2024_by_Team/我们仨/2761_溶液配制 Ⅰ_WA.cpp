#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1e5+10;
const long long MOD=1e9+7;
int n, q;
double a[N];
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
	for (int i=0;i<n;++i)scanf("%lf",&a[i]);
	sort(a, a+n);
	while (q--) {
		double x;
		scanf("%lf",&x);
		if (a[0] > x) l=0,r=n;
		else if (a[n-1] < x) l=n,r=0;
		else {
			l = lower_bound(a,a+n,x)-a;
			r = upper_bound(a,a+n,x)-a;
			if (a[l] >= x) l--;
	//		printf("%lld %lld %lld\n", l, r, m);
			l++;
			r = n-r;
		}
			m = n-l-r;
//			printf("%lld %lld %lld\n", l, r, m);
		if (m == 0) {
			printf("%lld\n", ((qpow(2, l)+MOD-1)%MOD)*((qpow(2,r)+MOD-1)%MOD)%MOD);
		} else {
			printf("%lld\n", (((qpow(2, l)+MOD-1)%MOD)*((qpow(2,r)+MOD-1)%MOD)%MOD +
								((qpow(2, m)+MOD-1)%MOD)*((qpow(2,l+r)+MOD)%MOD)%MOD)%MOD);
		}
	}
	return 0;
}

