#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	char name[20];
	int age;
	int a;
}x;
int main()
{
	x f[5];
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		scanf("%s%d%d",&f[i].name,&f[i].age,&f[i].a);
	}
	for(int i=0;i<m;i++)
	{
		f[i].age+=1;
		f[i].a=f[i].a+f[i].a*0.2;
		if(f[i].a>600)
		{
			f[i].a=600;
		}
	}
	for(int i=0;i<m;i++)
	{
		printf("%s %d %d\n",f[i].name,f[i].age,f[i].a);
	}
	return 0;
}