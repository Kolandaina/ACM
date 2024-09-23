#include<stdio.h>
long long Cab(int a)
{
	long long c=1;
	for(int i=1;i<=a;i++)
	{
		c*=i;
	}
	return c;
}
int main()
{
	int m;
	scanf("%d",&m);
	for(int k=0;k<m;k++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(b==0) printf("1\n");
		else
		{
			long long c=Cab(a)/(Cab(b)*Cab(a-b));
			printf("%lld\n",c);
		}	
	}
	return 0;
}