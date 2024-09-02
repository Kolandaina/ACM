#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1,d=0;d<n;i++)
	{
		for(int j=1;j<=i+1;j++)
		{
			cout<<i<<"/"<<j<<" ";
			d++;
		}
	}
	return 0;
}