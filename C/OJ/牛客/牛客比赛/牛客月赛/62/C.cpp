#include<bits/stdc++.h>
using namespace std;
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
int main()
{
	int n;
	cin>>n;
	int a[1000],b[1000];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	int flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int t=zuida(a[i],b[j]);
			if(t!=1)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			break;
		}
	}
	if(flag==1) cout<<"No";
	else cout<<"Yes";
	return 0;
}