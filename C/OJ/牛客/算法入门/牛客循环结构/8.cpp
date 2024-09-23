#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	double s=0,a=1,b=1,x=0;
	for(i=1;i<=n;i++)
	{
		
		x=a*b+x;
		b=b+2;
		a=-a;	
	    s+=(1/x);
	}
	printf("%.3lf",s);	
	return 0;
}