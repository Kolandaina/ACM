#include <bits/stdc++.h>
#define PI 3.14159265358979323846264338327950
using namespace std;

int main()
{
	int r, x;
	cin>>r>>x;
	double a=double(x)/r;
	double x1=x;
	while(x>2*PI*r*cos(a))
	{
		x-=2*PI*r*cos(a);
	}
	double t=x/cos(a)-x1;
	printf("%.10f\n",min(t,2*PI*r-t));
}
