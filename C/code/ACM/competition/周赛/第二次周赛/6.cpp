#include<stdio.h>
int main()
{
	int n;
	long long sum=0;
	long long a[100000]={0};
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(i!=0&&i!=n-1)
		{
			sum+=a[i];
		}
	}
	if(sum==n-2||(sum%2!=0&&n==3))
	{
		printf("-1");
		return 0;
	}
	long long m=0;
	for(int i=1;i<n-1;i++)
	{
		if(a[i]%2==0)
		{
			m+=a[i]/2;
		}
		else
		{
			m+=a[i]/2+1;
		}
	}
	printf("%lld",m);
	return 0;
}