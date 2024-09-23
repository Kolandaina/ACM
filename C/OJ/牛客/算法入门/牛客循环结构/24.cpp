#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,c[10];
	cin>>n;
	for(int i=0;i<3;i++)
	{
		cin>>a>>b;
		if(n%a==0) c[i]=(n/a)*b;
		else c[i]=(n/a+1)*b;
	}
	cout<<*min_element(c,c+3);
	return 0;
}