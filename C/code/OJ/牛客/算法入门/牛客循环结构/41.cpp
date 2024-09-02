#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	int s=0;
	cin>>m;
	while(1)
	{
		if(m%2==0) m/=2;
		else m=3*m+1;
		s++;
		if(m==1)
		{
			break;
		}
	}
	cout<<s;
	return 0;
}