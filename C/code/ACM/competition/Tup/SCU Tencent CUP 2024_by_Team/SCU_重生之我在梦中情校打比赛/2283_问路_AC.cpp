#include<bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
int main() {
	long double R, X;
	cin >> R >> X;
	if (R < 1e-8 || X < 1e-8) {
		cout << 0 << endl;
		return 0;
	}
	long double theta, XX, r, alpha;
	theta = X / R;
	r = R * cos(theta);
	XX = X - floor(X / (2 * pi * r)) * (2 * pi * r);
	alpha = XX / r;
	long double ans = abs(alpha * R - X);
	ans = min(ans, 2 * pi * R - ans);
	cout << fixed << setprecision(15) << ans << endl; 
	return 0;
}
