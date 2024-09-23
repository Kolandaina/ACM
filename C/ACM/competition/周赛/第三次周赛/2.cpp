#include<stdio.h>
int main()
{
	int n;
	int count=1;
	scanf("%d",&n);
	for(int i=2;i<=n/i;++i)
	{
		if(n%i==0)
		{
			count=n/i;
			break;
		}
	}
	printf("%lld %lld",count,n-count);
	return 0;
}