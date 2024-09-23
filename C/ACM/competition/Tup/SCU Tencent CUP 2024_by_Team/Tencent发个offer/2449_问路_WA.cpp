#include<bits/stdc++.h>
using namespace std;
double x,r,pi=acos(-1);
int main(){
	scanf("%lf%lf",&r,&x);
	double d=x/cos(x/r)-x;
	printf("%.15lf\n",min(d,2.0*pi*r-d));
	return 0;
}
