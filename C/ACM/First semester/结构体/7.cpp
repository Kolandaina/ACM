#include<stdio.h>
#include<string.h>
typedef struct node
{
	char name[50];
	int g;
}x;
int main()
{
	x f[10];
	int m;
	scanf("%d",&m);
	char t[100];
	for(int i=0;i<m;i++)
	{
		getchar();
		gets(f[i].name);
		scanf("%d",&f[i].g);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m-1-i;j++)
		{
			if(f[j].g<f[j+1].g)
			{
				int tt=f[j].g;
				f[j].g=f[j+1].g;
				f[j+1].g=tt;
				strcpy(t,f[j+1].name);
				strcpy(f[j+1].name,f[j].name);
				strcpy(f[j].name,t);
			}
		}
	}
	printf("%d %s\n",f[0].g,f[0].name);
	printf("%d %s\n",f[m-1].g,f[m-1].name);
	return 0;
}