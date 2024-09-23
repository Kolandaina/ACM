#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	if(m+n%7<8) cout<<m+n%7;
	else cout<<m+n%7-7;
	return 0;
}