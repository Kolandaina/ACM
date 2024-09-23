#include <iostream>
#include<cmath>
#include<cstdio>
const double pi=3.1415926;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double R,x;
	cin>>R>>x;
	double m=x/R;
	double r=R*cos(m);
	double a=(x/r);
	while(a>2*pi){
		a-=2*pi;
	}
	double ans=R*a-x;
	printf("%.7lf",min(ans,2*pi*R-ans));
	return 0;
}

