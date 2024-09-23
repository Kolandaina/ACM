#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	char name[20];
	int g;
}x;
int main()
{
	int n;
	char t[101];
	cin>>n;
	x f[101];
	for(int i=0;i<n;i++)
	{
		scanf("%s%d",&f[i].name,&f[i].g);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
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
	for(int i=0;i<n;i++)
	{
		printf("%s",f[i].name);
		printf(" %d\n",f[i].g);
	}
	return 0;
}