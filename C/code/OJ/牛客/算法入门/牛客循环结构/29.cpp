#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	for(int k=0;k<m;k++)
	{
		int n;
		cin>>n;
		if(n==1) cout<<"No\n";
		else
		{
			int flag=0;
			for(int i=2;i<n;i++)
			{
				if(n%i==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1) cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
	return 0;
}