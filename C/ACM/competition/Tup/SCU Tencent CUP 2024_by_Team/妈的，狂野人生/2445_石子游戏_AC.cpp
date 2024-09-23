#include<bits/stdc++.h>


using  namespace std;
int dp1[2000009];
int dp2[2000009];
int  main()
{
	int n;
	dp1[1]=1;///xianshou
	dp2[1]=0; 
	for(int i=2;i<=1000000;i++)
	{
		if(i%2==0)
		{
			dp1[i]=(dp1[i/2]&dp1[i-1])^1;
			dp2[i]=dp1[i]^1;  
		}
		else
		{
			dp1[i]=dp2[i-1];
			dp2[i]=dp1[i-1];
		}
		//if(i<=50) printf("%d %d\n",dp1[i],dp2[i]);
	}
	int tt=0;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
 	     if(dp1[n]==1)
 	     {
 	     	printf("Alice\n");
		  }
         else 
         {
         	printf("Bob\n");
		 }
	}
	
	return 0;
}
