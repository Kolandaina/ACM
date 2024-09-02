#include<bits/stdc++.h>
using namespace std;
#define int long long 
long long  n,m,k;
int  er[1032];
int can[32];
int wei[32];
int ge[32];
signed  main()
{
	cin>>n>>m>>k;
	er[0]=1;
	
	for(int i=1;i<=31;i++)er[i]=er[i-1]*2;
	for(int i=0;i<=31;i++)
	{
		int u=er[i];
		while(u>0)
		{
			wei[i]++;
			u=u/10;
		}
	}
	for(int i=0;i<=30;i++)can[i]=m-2-wei[i];
	if(k==1&&n==1)
	{
		if(can[0]>0)cout<<"{1},";
		else cout<<"-1";
		return 0;
	}
	if(k==1)
	{
		if(can[n]<2)cout<<"-1";
		else {
			for(int i=1;i<=n;i++)
			{
				cout<<"{"<<er[i]<<"}"<<",";
				if(i==n)cout<<",";
				cout<<endl;
			}
		}
		return 0;
	}
	ge[0]=1;
	for(int i=1;i<=n-2;i++)ge[i]=1;
	ge[n-1]=2;
	for(int i=0;i<n;i++)
	{
		if(ge[i]>can[i])
		{
			cout<<-1;
			return 0;
		}
	}
	k=k-2;
	int last=n-1;
	while(k!=0)
	{
		if(ge[0]<can[0])
		{
			ge[0]++;
			k--;
			continue;
		}
		int l=0;
		for(int i=last;i>=1;i--)
		{
			if(l==0)//还没放  
			{
				if(ge[i]+2<=can[i])
				{
					ge[i]=ge[i]+2;
					l=1;
				}
			}
			else ge[i]=ge[i]+1;
		}
		k--;
		if(l==0)
		{
			cout<<-1;
			return 0;
		}
	}
	for(int i=0;i<=n-1;i++)
	{
		cout<<"{"<<er[i]<<"}";
		for(int j=1;j<=ge[i];j++)cout<<",";
		cout<<endl;
	}
}
