#include<bits/stdc++.h>
using namespace std;
#define int long long 
int f1[20001];
int f2[20001];
int f3[20001];
int n;
int m1,m2,m3;
int v1[2010],w1[2010];
int v2[2010],w2[2010];
int v3[2010],w3[2010];
signed main()
{
	cin>>n;
	cin>>m1>>m2>>m3;
	for(int i=1;i<=m1;i++)cin>>v1[i]>>w1[i];
	for(int i=1;i<=m2;i++)cin>>v2[i]>>w2[i];
	for(int i=1;i<=m3;i++)cin>>v3[i]>>w3[i];
	
	for(int i=1;i<=m1;i++)
	{
		for(int j=n;j>=v1[i];j--)f1[j]=max(f1[j],f1[j-v1[i]]+w1[i]);
	}
	
	for(int i=1;i<=m2;i++)
	{
		for(int j=n;j>=v2[i];j--)f2[j]=max(f2[j],f2[j-v2[i]]+w2[i]);
	}
	
	
	for(int i=1;i<=m3;i++)
	{
		for(int j=n;j>=v3[i];j--)f3[j]=max(f3[j],f3[j-v3[i]]+w3[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		f1[i]=max(f1[i],f1[i-1]);
		f2[i]=max(f2[i],f2[i-1]);
		f3[i]=max(f3[i],f3[i-1]);	
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n-i;j++)
	ans=max(ans,f1[i]*f2[j]*f3[n-i-j]);
	cout<<ans;
} 
