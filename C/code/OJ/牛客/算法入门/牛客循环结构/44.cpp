#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	double n=1;
	double s=0;
	while(1)
	{
		
		s+=1/n;
		if(s>m)
		{
			break;
		}
		n++;
	}
	cout<<n;
	return 0;
}