#include<bits/stdc++.h>


using  namespace std;
const double P= 3.14159265335897;

int  main()
{
	double R,x;
	scanf("%lf%lf",&R,&x);
	if(R==0.0000) {
	printf("0.000000 0");return 0;}
	double O=1.0*x/R;
	double r=R*cos(O);
	//double X=1.0*R*x/r;
	double xx=x;
	x-= 1.0*(int)(x/(2*P*r))*(2*P*r);
//	printf("%.10lf %.10lf %.10lf\n",x,xx,r);
//	while(x>=2*P*r)
//	{
//	  x-=2*P*r;	
//	}
	if(x>P*r )
	{
	//	printf("1111\n");
       double ans=x*R/r;
       ans-=xx;
	   printf("%.10lf %.10lf\n",min(ans,2*P*R-ans),2*P*R-ans);		
	}
	else
	{
		//printf("111111\n");
	  double ans=x*R/r;
	  printf("%.10lf",max(ans-xx,xx-ans));	
	}  
	//double ans=fabs(X-1.0*x);
	//printf("%.10lf\n",ans);
	
	return 0;
}
