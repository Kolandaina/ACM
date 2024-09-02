#include<stdio.h>
long long zuida(long long a,long long b)
{
	long long c=a%b;
	while(c!=0)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
int main()
{
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		long long a,b;
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",zuida(a,b));
	}
	return 0;
}