#include <bits/stdc++.h>
#define PI 3.14159265358979323846264338327950
#define ld long double
using namespace std;


int main()
{
	ld r, x;
	cin>>r>>x;
	long double a=double(x)/r;
	long double x1=x;
	while(x>(ld)(2)*(ld)(PI)*r*cos(a))
	{
		x-=(ld)(2)*(ld)(PI)*r*cos(a);
	}
	long double t=x/cos(a)-x1;
 //cout<<t<<" "<<((ld)(2*PI)*r-t)<<endl;
	ld ans1=t;
	ld ans2=((ld)(2*PI)*r-t);
 	if(ans1>(ld)(PI)*r) cout<<fixed<<setprecision(10)<<ans2<<endl;
 	else cout<<fixed<<setprecision(10)<<ans1<<endl;
	//printf("%.8lf\n",min(ans1,ans2));
}
