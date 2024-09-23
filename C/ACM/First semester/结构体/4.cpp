#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int a;
	int b;
	int c;
}x;
int main()
{
	int m;
	cin>>m;
	x f[20];
	int n[20];
	int j=0,o=0;
	for(int i=0;i<m;i++)
	{
		cin>>f[i].a>>f[i].b>>f[i].c;
	}
	for(int i=0;i<m;i++)
	{
		if(f[i].b+f[i].c>140&&f[i].b*0.8+f[i].c*0.2>80)
		{
			j++;
			n[o++]=f[i].a;
		}
	}
	cout<<j<<"\n";
	sort(n,n+j,greater<int>());
	for(int i=0;i<j;i++)
	{
		cout<<n[i]<<" "<<endl;
	}
	return 0;
}
