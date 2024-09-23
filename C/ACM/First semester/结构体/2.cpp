#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	char name[10];
	int a;
	int b;
	int c;
}x;
int main()
{
	int m;
	cin>>m;
	char t[10];
	x f[1000];
	for(int i=0;i<m;i++)
	{
		cin>>f[i].name>>f[i].a>>f[i].b>>f[i].c;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m-1-i;j++)
		{
			if(f[j].a+f[j].b+f[j].c<f[j+1].a+f[j+1].b+f[j+1].c)
			{
				int aa=f[j].a;
				f[j].a=f[j+1].a;
				f[j+1].a=aa;

				int bb=f[j].b;
				f[j].b=f[j+1].b;
				f[j+1].b=bb;

				int cc=f[j].c;
				f[j].c=f[j+1].c;
				f[j+1].c=cc;

				strcpy(t,f[j+1].name);
				strcpy(f[j+1].name,f[j].name);
				strcpy(f[j].name,t);
			}
		}
	}
	cout<<f[0].name<<" "<<f[0].a<<" "<<f[0].b<<" "<<f[0].c;
	return 0;
}