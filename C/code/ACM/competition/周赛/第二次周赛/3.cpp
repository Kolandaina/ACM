#include<stdio.h>
int main()
{
	long long n,q;
	long long l,r;
	scanf("%lld%lld",&n,&q);
	long long a[500000],s[500000]={0};
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}

	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",s[r]-s[l-1]);
	}
	return 0;
}