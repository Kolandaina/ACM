#include<bits/stdc++.h>
using namespace std;
double x,r,pi=acos(-1);
int main(){
	scanf("%lf%lf",&r,&x);
	double d=pi*r/2.0;
	printf("%.15lf",x/cos(x/r)-x);

	return 0;
}
