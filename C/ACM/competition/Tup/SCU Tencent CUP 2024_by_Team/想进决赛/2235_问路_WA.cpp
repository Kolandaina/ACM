#include <iostream>
#include <math.h>
using namespace std;

int r, x;
int main(){
	scanf("%d %d",&r,&x);
	double theta = 1.0 * x / r;
	double k = r * cos(theta);
	double aph = x / k;
	double ans = r * aph - x;
	printf("%.10lf",ans);
	return 0;
}

