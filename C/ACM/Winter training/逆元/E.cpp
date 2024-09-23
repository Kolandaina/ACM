#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000;
int m[N];
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int mul(int y)
{
	int sum=0;
	for(int i=1;i*i<=y;i++)
	{
		if(y%i==0)
		{
			m[sum++]=i;
			if(i*i!=y) m[sum++]=y/i;
		}
	}
	return sum;
}
signed main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int x=gcd(a,b);
		int s=mul(x);
		if(c>s) cout<<"-1"<<endl;
		else
		{
			sort(m,m+s,greater<int>());
			cout<<m[c-1]<<endl;;
		}
	}
	return 0;
}