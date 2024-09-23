#include<stdio.h>
int mt(int m)
{
	if(m==0) return 2;
	else return mt(m-1)*2-1;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",mt(n));
	return 0;
}