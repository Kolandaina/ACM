#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000000];
signed main()
{
	int n,sum=0,num=0,flag=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==n) continue;
		if(a[i]!=0) flag=1;
		if(flag==1)
		{
			if(a[i]==0) sum++;
			else sum+=a[i];
		}
	}
	cout<<sum;
	return 0;
}