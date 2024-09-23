#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5, mod = 1e9+7;
int n,q,w[N+5];

int qpow(int base, int p){
	int res = 1;
	while (p){
		if (p & 1)
		  res = 1ll * res * base % mod;
		base = 1ll * base * base % mod;
		p >>= 1;
	}
	return res;
}

int main(){
	scanf("%d %d",&n,&q);
	for (int i = 1; i <= n; i ++){
		int a,b;
		scanf("%d.%d",&a,&b);
		w[i] = a*1000 + b;
	}
	sort(w+1, w+n+1);
	while (q --){
		int a, b, p;
		scanf("%d.%d",&a,&b);
		p = a*1000 + b;
		int x = lower_bound(w+1, w+n+1, p) - w - 1;
		int y = upper_bound(w+1, w+n+1, p) - w;
		int l = x, r = n-y+1, m = y-x-1;
		int ans1 = 1ll * (qpow(2, l) - 1) * (qpow(2, r) - 1) % mod;
		int ans2 = 1ll * qpow(2, n-m) * (qpow(2, m) - 1) % mod;
		printf("%d\n",(ans1+ans2)%mod);
	}
	return 0;
}

