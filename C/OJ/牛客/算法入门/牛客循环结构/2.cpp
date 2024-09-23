#include<stdio.h>
int main()
{
	int m;
	int n=0;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			n++;
			printf("%4d",n);
		}
		printf("\n");
	}
	return 0;
}
