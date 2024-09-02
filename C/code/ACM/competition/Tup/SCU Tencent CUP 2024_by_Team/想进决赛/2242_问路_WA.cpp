#include <iostream>
#include <cmath>
using namespace std;

int r, x;
int main(){
	scanf("%d %d",&r,&x);
	long double theta = 1.0 * x / r;
	long double ans = x / cos(theta) - x;
	printf("%.10Lf",ans);
	return 0;
}

