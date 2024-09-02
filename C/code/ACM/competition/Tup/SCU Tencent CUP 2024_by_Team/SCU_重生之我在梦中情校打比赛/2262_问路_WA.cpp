#include<bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
int main() {
	long double R, X;
	cin >> R >> X;
	if (R < 1e-10 || X < 1e-10) {
		cout << 0 << endl;
		return 0;
	}
	long double theta, XX, r, alpha;
	theta = X / R;
	r = R * cos(theta);
	XX = X - int(X / (2 * pi * r) - 1e-8) * (2 * pi * r);
	alpha = XX / r;
	cout << fixed << setprecision(10) << alpha * R - X << endl; 
	return 0;
}
