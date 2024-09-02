#include<bits/stdc++.h>
using namespace std;
int nod(int x)
{
	int a=0;
	for(int i=1;i<=x;i++)
	{
		a+=i;
	}
	return a;
}
int main()
{
	int m;
	cin>>m;
	int n=0;
	for(int i=1;i<=m;i++)
	{
		n+=nod(i);
	}
	cout<<n;
	return 0;
}
