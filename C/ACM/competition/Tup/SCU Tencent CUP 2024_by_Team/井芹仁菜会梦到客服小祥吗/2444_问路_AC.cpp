#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main () {
	double x, R;
	const double pi_2 = 3.1415926535897932384626433832795*2;
	const double pi = 3.1415926535897932384626433832795;
	cin >> R >> x;
	double r = R * cos(x / R);
	double a = x / r;
	while (a > pi_2) {
		a -= pi_2;
	}
	double y = a * R, ans, halfR = pi * R;
	if (y - x >= halfR) {
		printf("%.15lf\n", abs(pi_2 * R - y + x));
	} else {
		printf("%.15lf\n", abs(y - x));
	}
}
