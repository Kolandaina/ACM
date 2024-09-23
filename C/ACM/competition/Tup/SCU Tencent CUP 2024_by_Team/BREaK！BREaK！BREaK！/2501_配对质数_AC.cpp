#include<bits/stdc++.h>
using namespace std;
int vis[5000005];
int main()
{
	int t;
	cin>>t;
	for(int i=2;i<=5000001;++i)
	{
		if(vis[i])continue;
		for(int j=i*2;j<=5000001;j+=i)
		{
			vis[j]=1;
		}
	}
	while(t--)
	{
		int n;scanf("%d",&n);
		if(!vis[2*n+1])
		{
			for(int i=1;i<=n;++i)
			{
				printf("%d %d\n",i,2*n+1-i);
			}
		}
		else
		{
			int flag=0;
			for(int i=2;i<=2*n-2;++i)
			{
				if(vis[2*i+1]==0&&vis[2*i+1+2*n]==0)
				{
					for(int j=1;j<=i;++j)
					{
						printf("%d %d\n",j,2*i+1-j);
					}
					for(int j=2*i+1;j<=2*n;++j)
					{
						int k=2*i+1+2*n-j;
						if(k>j)
						{
							printf("%d %d\n",j,k);
						}
						else break;
					}
					break;
				}
			}
		}
	}
}
