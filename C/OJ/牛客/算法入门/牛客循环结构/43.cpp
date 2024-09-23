#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m=0,n,a=12,b=0;
	while(a--)
	{
		m+=300;
		cin>>n;
		m-=n;
		if(m>=100)
		{
			m-=100;
			b+=100;
		}
		if(m<0)
		{
			cout<<a-12;
			break;
		}
	}
	if(m>0)
	{
		cout<<m+b*1.2;
	}
	return 0;
}