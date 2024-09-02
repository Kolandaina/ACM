#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m=0;
	cin>>n;
	for(int i=0;i<20;i++)
	{
		m+=(n%10);
		n/=10;
		if(n==0)
		{
			break;
		}
	}
	cout<<m;
	return 0;
}