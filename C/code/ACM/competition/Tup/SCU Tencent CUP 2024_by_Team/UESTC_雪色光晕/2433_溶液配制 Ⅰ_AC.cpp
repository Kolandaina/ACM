#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=501010;
const ll inf=0x3f3f3f3f;
const ll p=1e9+7;

ll T;
ll n,Q;
map <int, ll> f;

inline ll read() {
	ll sum = 0, ff = 1; char c = getchar();
	while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
	while(c>='0'&&c<='9') { sum = sum * 10 + c -'0'; c = getchar(); }
	return sum * ff;
}

int a[N];

inline ll ksm(ll aa,ll bb) {
	ll sum = 1;
	while(bb) {
		if(bb&1) sum = sum * aa%p;
		bb >>= 1; aa = aa * aa %p;
	}
	return sum;
}

int main() {
	int x,y;
	cin>>n>>Q;
	for(ll i=1;i<=n;i++) {
		x = read(); y = read();
		x = x*1000+y;
		a[i] = x;
		f[x]++;
	}
	sort(a+1,a+n+1); a[n+1] = inf;
//	for(int i=1;i<=n;i++) cout<<a[i]<<", ";
	while(Q--) {
		x = read(); y = read();
		x = x*1000 + y;
		ll l=1, r=n+1, mid, res=1;
		while(l<=r) {
			mid = l+r >> 1;
			if(a[mid]>=x) res = mid, r = mid-1;
			else l = mid+1;
		}
		ll zuo = res-1;
		ll zhong = f[x];
		ll you = n-zuo-zhong;
//		cout<<zuo<<" "<<zhong<<" "<<you<<endl;
		ll ans1 = (ksm(2,zuo+you)-ksm(2,zuo)-ksm(2,you)+1+p+p) %p;
		ll ans2 = (((ksm(2,zhong)-1)*ksm(2,zuo+you)%p)+p) %p;
		
		cout<<((ans1+ans2)%p+p)%p<<"\n";
	}
	
	return 0;
}
/*

3 3
10.000
15.000
16.000
00.0
15.000
22.000

*/

