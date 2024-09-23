#include<stdio.h>
int zuida(int a,int b)
{
	int c=a%b;
	while(c!=0)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
int zuixiao(int a,int b)
{
	int max,min;
	if(a>b) max=a;
	else max=b;
	if(a>b) min=b;
	else min=a;
	int i=1;
	int temp=0;
	while(i++)
	{
		temp += max;
		if(temp%min==0) break;
	}
	return temp;
}
int main()
{
	int m;
	scanf("%d",&m);
	for(int k=0;k<m;k++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int x=zuida(a,b);
		int y=zuixiao(a,b);
		printf("%d %d\n",x,y);
	}
	return 0;
}