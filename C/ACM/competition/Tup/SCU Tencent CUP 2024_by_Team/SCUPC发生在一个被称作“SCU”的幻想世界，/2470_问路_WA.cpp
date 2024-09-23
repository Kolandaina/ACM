#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef double db;

const int N = 1e6 + 10;

const double PI = acos(-1.0);
const double pi2 = PI * 2.0;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	double R, X;
	cin >> R >> X;
	double theta = X / R;
	double r = R * cos(theta);
	double phi1 = X / r;
//	while (phi1 > pi2) phi1 -= pi2;
//	double phi2 = (-X / R + pi2);
	double phi2 = -X / R;
//	while (phi2 > pi2) phi2 -= pi2;
	double dphi = phi1 + phi2;
//	while (dphi > pi2) dphi -= pi2;
//	dphi = min(dphi, pi2 - dphi);
	double dX = R * dphi;
	cout << fixed << setprecision(12) << dX << endl;
	return 0;
}
