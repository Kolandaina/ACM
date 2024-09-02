#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<"The maximum number is : "<<max(a,max(b,c))<<"\n";
	cout<<"The minimum number is : "<<min(a,min(b,c));
	return 0;
}