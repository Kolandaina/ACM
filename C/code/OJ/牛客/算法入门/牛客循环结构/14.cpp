#include<bits/stdc++.h>
using namespace std;
int node(int a)
{
	for(int i=2;i<a;i++)
	{
		if(a%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		int s=0;
		for(int j=2;j<=a;j++)
		{
			if(node(j)) s++;
		}
		cout<<s<<endl;
	}
	return 0;
}