#include<bits/stdc++.h>
using namespace std;

#define pi 3.1415926535897932384626433832795
double r, x;

int main(){
	scanf("%lf%lf", &r, &x);
	double r1 = r*cos(x/r);
	double temp1 = x;
	while(temp1 > 2*pi*r1) temp1-=2*pi*r1;
	temp1 = 2*pi*r1-temp1;
	double temp2 = temp1*r/r1;
	double ans = temp2+x;
	while(ans>2*pi*r) ans-=2*pi*r;
	if(ans>=pi*r) printf("%.15lf",2*pi*r-ans);
	else printf("%.15lf",ans);
	return 0;
}
