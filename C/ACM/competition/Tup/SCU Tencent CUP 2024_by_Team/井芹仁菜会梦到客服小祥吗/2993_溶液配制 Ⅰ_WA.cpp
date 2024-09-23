#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
long long mod = 1e9+7;

int main () {
	int n, q;
	cin >> n >> q;
	vector<double> a(n);
	for (int i {0}; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < q; ++i) {
		double x;
		cin >> x;
		int p = upper_bound(a.begin(), a.end(), x) - a.begin();
		if ((p == n && a[p-1] != x) || p == 0) { cout << "0\n"; continue;}
		//cout << "p: " << p << " ";
		int bigger, less, equal{0};
		bigger = n - p;
		if (a[p - 1] != x) {
			less = p;
		} else {
			int t = p-1;
			while (t >= 0 && a[t] == x) {
				++equal;
				--t;
			}
			less = t+1;
		}
		//cout << "less:" << less << " bigger: " << bigger << endl;
		long long ans = 0, lessCnt, eqCnt, bigCnt;
		less = min(less, 62);
		lessCnt = (1LL << less) % mod;
		bigger = min(bigger, 62);
		bigCnt = (1LL << bigger) % mod;
		if (equal) {
			equal = min(62, equal);
			eqCnt = (1LL << equal) % mod;
		} else {
			eqCnt = 0;
		}
		//cout << lessCnt << " " << eqCnt << " " << bigCnt << endl;
		if (a[p - 1] != x) {
			ans = lessCnt * bigCnt - lessCnt - bigCnt + 1LL;
			//cout << "ans: " << ans << endl;
			ans %= mod;
		} else {
			ans = ((eqCnt - 1)* lessCnt  % mod )* bigCnt % mod;
			ans += lessCnt * bigCnt - lessCnt - bigCnt + 1LL;
			ans %= mod;
		}
		cout << ans << "\n";
	}
}
