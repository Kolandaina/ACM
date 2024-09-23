#include<stdio.h>
long long jie(int m)
{
    if(m==1) return 1;
    else return m*(jie(m-1));
}
int main()
{
	int m;
	scanf("%d",&m);
	printf("%lld",jie(m));
	return 0;
}