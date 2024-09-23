#include <bits/stdc++.h>
using namespace std;
#define N 20005
#define LL long long

LL n,m1,m2,m3;
LL f[4][N];
LL v[4][N],w[4][N];//value weight

int main()
{
	//freopen("in.txt","r",stdin);
	cin>>n;
	cin>>m1>>m2>>m3;
	
	for(int i=1;i<=m1;i++)
	{
		cin>>w[1][i]>>v[1][i];
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>w[2][i]>>v[2][i];
	}
	for(int i=1;i<=m3;i++)
	{
		cin>>w[3][i]>>v[3][i];
	}
	
	for(int i=1;i<=m1;i++)
	{
		for(int j=n;j>=w[1][i];j--)
		{
			if(j>=w[1][i])
			f[1][j]=max(f[1][j-w[1][i]]+v[1][i],f[1][j]);
		}
	}
	
	for(int i=1;i<=m2;i++)
	{
		for(int j=n;j>=w[2][i];j--)
		{
			if(j>=w[2][i])
			f[2][j]=max(f[2][j-w[2][i]]+v[2][i],f[2][j]);
		}
	}
	
	for(int i=1;i<=m3;i++)
	{
		for(int j=n;j>=w[3][i];j--)
		{
			if(j>=w[3][i])
			f[3][j]=max(f[3][j-w[3][i]]+v[3][i],f[3][j]);
		}
	}
	
/*	for(int i=1;i<=n;i++)
	{
		cout<<f[1][i]<<" "<<f[2][i]<<" "<<f[3][i]<<"\n";
	}*/
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i+j<n)
				ans=max(ans,f[1][i]*f[2][j]*f[3][n-i-j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
