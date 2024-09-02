#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int hx(int n,int x)
{
	if(n==0) return 1;
	else if(n==1) return 2*x;
	else
	{
		return 2*x*hx(n-1,x)-2*(n-1)*hx(n-2,x);
	}
}
signed main()
{
	int n,x;
	cin>>n>>x;
	cout<<hx(n,x);
	return 0;
}