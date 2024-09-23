#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		while(n%i==0)
		{
			n/=i;
			m++;
		}
	}
	if(m%2==0)
	{
		cout<<"Johnson";
	}
	else cout<<"Nancy";
}