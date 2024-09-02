#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a;
	cin>>a;
	if(a%3==0) cout<<(a/3)*2;
	else cout<<(a/3)*2+1;
	return 0;
}