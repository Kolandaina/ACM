#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	char name[10];
	int a;
}x;
int main()
{
	int q;
	cin>>q;
	for(int k=0;k<q;k++)
	{
		int m,n;
		cin>>n>>m;
		x f[50];
		for(int i=0;i<n;i++)
		{
			cin>>f[i].name>>f[i].a;
		}
		for(int i=0;i<m;i++)
		{
			int p;
			cin>>p;
			if(p==2)
			{
				char tt[10];
				int b;
				cin>>tt>>b;
				for(int j=0;j<n;j++)
				{
					if(strcmp(tt,f[j].name)==0)
					{
						f[j].a=b;
					}
				}
			}
		    else
			{
				char tt[10];
				cin>>tt;
				for(int j=0;j<n;j++)
				{
					if(strcmp(tt,f[j].name)==0)
					{
						cout<<f[i].a;
					}
				}
			}	
		}
	}
	return 0;
}