#include<stdio.h>
long long feibo(int m)
{
	if(m==2||m==1)
	{
		return 1;
	}
	return feibo(m-1)+feibo(m-2);
	
}
int main()
{
	int m;
	scanf("%d",&m);
	printf("%lld",feibo(m));
	return 0;
}