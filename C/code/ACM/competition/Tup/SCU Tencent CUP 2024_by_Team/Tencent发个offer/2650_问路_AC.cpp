#include<bits/stdc++.h>
using namespace std;
double x,r,pi=acos(-1);
int main(){
	scanf("%lf%lf",&r,&x);
	double d=x/cos(x/r)-x;
	double D=2.0*pi*r;
	while(d>D){
		d-=D;
	}
	printf("%.15lf\n",min(d,D-d));
	return 0;
}
