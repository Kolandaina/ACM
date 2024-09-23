#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main () {
	double x, r;
	cin >> r >> x;
	double y = r * cos(x / r);
	double a = x/y;
	double R = r * a;
	printf("%.8lf\n", abs(R-x));
}
