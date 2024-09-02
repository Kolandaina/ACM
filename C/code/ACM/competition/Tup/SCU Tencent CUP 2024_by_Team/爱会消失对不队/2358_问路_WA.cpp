#include<iostream>
#include<cmath>
using namespace std;
double aabs(double a){
	if (a <0) a = -a;
	return a;
}
int main(){
	double s;
	double x, r;
	cin >> r >> x;
	s = x / r;
	double ans = aabs(x *(1 - 1 / cos(s)));
	printf("%llf", ans);
	// while (1);
	return 0;
}