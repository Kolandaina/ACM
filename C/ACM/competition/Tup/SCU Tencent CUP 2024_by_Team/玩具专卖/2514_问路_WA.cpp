#include<bits/stdc++.h>
using namespace std;
double R,X;
double ans;
inline void work()
{
	scanf("%lf%lf",&R,&X);
	ans=X*(1.0/cos(X/R)-1.0);
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
