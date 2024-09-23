#include<bits/stdc++.h>
using namespace std;
stack<int>g;
int a[2005],n,tot,b[2005];
int main()
{
	scanf("%d",&n);
	int now=0;
	int tot=n;
	for(int i=1;i<=n;++i)
	{
		printf("? ");
		for(int j=1;j<i;++j)printf("%d",a[j]);
		printf("0");puts("");fflush(stdout);
		int x;scanf("%d",&x);
		if(x)a[i]=0;
		else a[i]=1;
		if(i%20==0||i==n)
		{
			printf("? ");
			for(int j=1;j<=i;++j)printf("%d",a[j]);
			puts("");fflush(stdout);
			int x;scanf("%d",&x);
			if(!x)
			{
				tot=i;
				for(int m=max(i-20,1);m<=i;++m)
				{
					printf("? ");
	        	    for(int j=1;j<=m;++j)printf("%d",a[j]);
	        	    puts("");fflush(stdout);
	        	    int x;scanf("%d",&x);
	        	    if(!x)
	        	    {
	        	    	tot=m-1;break;
					}
				}
				break;
			}
		}
	}
	int m=n-tot;
	for(int i=m;i>=1;--i)
	{
		printf("? ");
		printf("0");
		for(int j=i+1;j<=m;++j)printf("%d",b[j]);
		for(int j=1;j<=tot;++j)printf("%d",a[j]);
		puts("");fflush(stdout);
		int x;scanf("%d",&x);
		if(!x)b[i]=1;
		else b[i]=0;
	}
	printf("! ");
	for(int i=1;i<=m;++i)printf("%d",b[i]);
	for(int i=1;i<=tot;++i)printf("%d",a[i]);
	puts("");fflush(stdout);
}
