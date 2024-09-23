#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244352;
int qmi(int x,int b,int p)
{
	int res = 1;
	x%=p;
	while(b)
	{
		if(b&1) res = res * x % p;
		b >>= 1;
		x = x * x % p;
	}
	return res;
}
signed main()
{
	int x,n;
	scanf("%lld%lld",&x,&n);
	for( int i = 1; i <= n; i++)
	{
		int b;
		scanf("%lld",&b);
		int res=qmi(x,b,p);
		cout << res << ' ';
	}
	return 0;
}
