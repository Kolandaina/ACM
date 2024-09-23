#include<stdio.h>
int main()
{
	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%lld\n",a*b*2+b*c*2+a*c*2);
	printf("%lld",a*b*c);
	return 0;
}