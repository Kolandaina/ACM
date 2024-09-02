#include <bits/stdc++.h>

#define int long long

const int mod = 1e9 + 7;

int qmi(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n, q;
	std::cin >> n >> q;
	
	std::vector<double> w(n);
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> w[i]; 
		if(w[i] == 0) cnt++;
	}
	
	while(q--) {
		double x;
		std::cin >> x;
		int a = std::lower_bound(w.begin(), w.end(), x) - w.begin();
		int c = std::upper_bound(w.begin(), w.end(), x) - w.begin();
		int b = 0;
		if(w[a] != x) {
			a--;
			b = c - a + 1 - 2;	
			a++;
		}else {
			b = c - a;
		}
		c = n - b - a;
//		std::cout << a << ' ' << b << ' ' << c << '\n';
		
		int res = 0;
		
//		res += (qmi(2, c) - 1 + mod) % mod * ((qmi(2, a + b) - 1 + mod) % mod) % mod;
//		res = (res + mod) % mod; 

		res += (qmi(2, b) - 1 + mod) % mod * (qmi(2, a + c)) % mod + (qmi(2, a) - 1 + mod) % mod * ((qmi(2, c) - 1 + mod) % mod) % mod;
		res %= mod;
		
		std::cout << res << '\n';
	}
}

signed main () {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);

	int t = 1;
//	cin >> t;
	for(int i = 0; i < t; ++i) solve ();

	return 0;
}

//3 3
//10.000
//15.000
//16.000
//00.000
//15.000
//15.999
