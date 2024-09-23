#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<"circumference="<<sqrt(0.25*(c*c*a*a-((c*c+a*a-b*b)/2))*(c*c*a*a-((c*c+a*a-b*b)/2)));
	return 0;
}