#include<bits/stdc++.h>


using  namespace std;
const double P= 3.14159265335897;

int  main()
{
	double R,x;
	scanf("%lf%lf",&R,&x);
	if(R==0.0000) {
	printf("0.0000000");return 0;}
	double O=1.0*x/R;
	double r=R*cos(O);
	double X=1.0*R*x/r;
	while(X>=2*P*R)
	{
	  X-=2*P*R;	
	}  
	double ans=fabs(X-1.0*x);
	printf("%.10lf\n",ans);
	
	return 0;
}
