#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
double R,X,r,d,ans;
double mo(double A,double B){
	return A-floor(A/B)*B;
}
inline void work()
{
	scanf("%lf%lf",&R,&X);
	r=R*cos(X/R);
	d=mo((X/r-X/R),(2*pi));
	d=min(2*pi-d,d);
	ans=d*R;
	printf("%.7lf\n",ans);
}
signed main()
{
	work();
	return 0;
}
/*
5 3

10 10
*/
