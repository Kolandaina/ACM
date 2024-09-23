#include<bits/stdc++.h>
using namespace std;
int mod(int m)
{
	if(m==1||m==2) return 1;
	else return mod(m-1)+mod(m-2);
}
int main()
{
	int n;
	cin>>n;
	cout<<mod(n);
	return 0;
}