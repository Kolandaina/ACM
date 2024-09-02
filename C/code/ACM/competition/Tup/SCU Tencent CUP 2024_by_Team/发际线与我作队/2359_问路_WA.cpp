#include<bits/stdc++.h>
using namespace std;
//const int N=1e5+5;
//int n,m;
#define PI 3.1415926

void sovle(){
	int R,x;
	scanf("%d%d",&R,&x);
	// double res = 1.0 * x * (1.0/cos(1.0 * x/r) - 1);
	double r = R * cos(1.0*x/R);
	double x_ = x;
	while(x_ > 2 * PI * r)
		x_ = x_ - 2 * PI * r;
	double res = abs(R * x_ / r - x);
	printf("%.15lf", res);
}
int main(){
	sovle();
}
