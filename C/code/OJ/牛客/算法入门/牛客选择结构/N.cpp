#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,m[6];
	cin>>a>>b>>c;
	m[0]=a+b+c;
	m[1]=a*b*c;
	m[2]=a*b+c;
	m[3]=a+b*c;
	m[4]=a*(b+c);
	m[5]=(a+b)*c;
	cout<<*max_element(m,m+6);
	return 0;
}