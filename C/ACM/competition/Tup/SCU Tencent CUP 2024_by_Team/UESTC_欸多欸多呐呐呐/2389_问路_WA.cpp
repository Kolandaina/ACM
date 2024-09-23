#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	long double r, x;
	cin >> r >> x;
	long double thita = x / r;
	long double ans = (1.L / cos(thita) - 1) * x;
	ans  = ans - floor(ans / (2 * acos(-1) * r)) * (2 * acos(-1) * r);
	ans = min(ans, 2 * acos(-1) * r - ans);
	cout << fixed << setprecision(18) << (1.L / cos(thita) - 1) * x << '\n';
	return 0;
}

