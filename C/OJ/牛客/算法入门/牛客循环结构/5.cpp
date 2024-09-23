#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)>0)
	{
        for(int i=1; i<=n+1;++i)
		{
            for(int j=1;j<=(n+1-i)*2;++j)
			{
				printf(" ");
			}
            for(int j=1;j<=i;++j)
			{
				printf("*");
			}
            printf("\n");
        }
        for (int i=n;i>0;--i)
		{
            for (int j=1;j<=(n+1-i)*2;++j)
			{
				printf(" ");
			}
            for (int j=1;j<=i;++j)
			{
				printf("*");
			}
            printf("\n");
        }
    }
    return 0;
}