#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	if(m%2==0) cout<<0-m/2;
	else cout<<m+(0-(m-1)/2);
	return 0;
}