#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<min(b,c)<<" ";
	if(b+c<=a)
	{
		cout<<"0";
	}
	else
	{
		cout<<max(b,c)-min(b,c);
	}
	return 0;
}