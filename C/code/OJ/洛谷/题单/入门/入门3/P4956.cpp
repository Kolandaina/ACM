#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,k=1,n;
	cin>>n;
	while(1)
	{
		for(x=100;x>0;x--)
			if((7*x+21*k)*52==n)
			{
				cout<<x<<endl;
				cout<<k;
				return 0;
			}
		k++;
	}
	return 0;
}