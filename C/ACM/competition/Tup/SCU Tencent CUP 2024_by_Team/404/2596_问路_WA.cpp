#include <bits/stdc++.h>
#define PI 3.14159265358979323846264338327950
using namespace std;

int main()
{
	int r, x;
	cin>>r>>x;
	long double a=double(x)/r;
	long double x1=x;
	while(x>2*PI*r*cos(a))
	{
		x-=2*PI*r*cos(a);
	}
	double t=x/cos(a)-x1;
	printf("%.8f\n",min(t,2*PI*r-t));
}
