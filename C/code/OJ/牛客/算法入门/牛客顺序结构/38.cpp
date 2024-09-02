#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c,x,y,z;
	cin>>x>>y>>z;
	a=sqrt(x*y/z);
	b=sqrt(y*z/x);
	c=sqrt(z*x/y);
	cout<<(a+b+c)*4;
	return 0;
}