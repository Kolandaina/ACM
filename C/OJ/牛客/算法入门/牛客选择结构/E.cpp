#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int m,n;
	cin>>m>>n;
	if(n%m==0) cout<<m+n;
	else cout<<n-m;
	return 0;
}