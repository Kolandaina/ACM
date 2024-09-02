#include<stdio.h>
int main()
{
	double f=0;
	double x;
	scanf("%lf",&x);
	if(x>=0&&x<5){
		f=-1*x+2.5;
		printf("%.3f",f);
	}
	else if(x>=5&&x<10){
		f=2-1.5*(x-3)*(x-3);
		printf("%.3f",f);
	}
	else if(x<20&&x>=10){
		f=x/2-1.5;
		printf("%.3f",f);
	}
	return 0;
}