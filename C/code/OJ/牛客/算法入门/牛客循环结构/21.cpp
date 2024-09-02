#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,d=1,s=0;
	cin>>m;
	for(int i=1;d<=m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(d>m)
			{
				break;
			}
			s+=i;
			d++;
		}
	}
	cout<<s;
	return 0;
}