#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	char m[1020];
	getchar();
	scanf("%s",&m);
	for(int i=0;i<n;i++)
	{
		if(m[i]!='L') m[i]='C';
	}
	for(int i=0;i<n;i++)
	{
		if(m[i]=='L')
		{
			if(m[i-1]!='L') m[i-1]='.';
			if(m[i+1]!='L') m[i+1]='.';
		}
	}
	for(int i=0;i<n;i++) printf("%c",m[i]);
	return 0;
}