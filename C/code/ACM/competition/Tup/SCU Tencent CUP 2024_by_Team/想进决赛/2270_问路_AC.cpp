#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.1415926;
int r, x;
int main(){
	scanf("%d %d",&r,&x);
	long double theta = 1.0 * x / r;
	long double ans = x / cos(theta) - x;
	while (ans > 2 * pi * r)
	  ans -= 2 * pi * r;
	if (ans > pi * r)
	  ans = 2*pi*r - ans;
	printf("%.10Lf",ans);
	return 0;
}

