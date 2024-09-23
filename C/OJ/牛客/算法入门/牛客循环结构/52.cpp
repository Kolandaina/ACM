#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m[10][10];
	int a,b;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>m[i][j];
			if(m[i][j]==1)
			{
				a=i;
				b=j;
			}
		}
	}
	int s=abs(3-a)+abs(3-b);
	cout<<s;
	return 0;
}