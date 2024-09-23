#include<bits/stdc++.h>


using  namespace std;
const int p=1e7+10;
int k;
int prim[p],cnt,vis[p];
int dis[2000009];
void ola(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i])prim[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*prim[j]>n)break;
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
}  

void chuli(int k)
{
	int arr[10];
	arr[1]=k-3;
	arr[2]=k-2;
	arr[3]=k-1;
	arr[4]=k;
	bool flag=false;
  for(int i=2;i<=4;i++)
  {
  	 if(vis[arr[1]+arr[i]]==0)
	   {
	      if(i==2)
		  {
		     if(vis[arr[3]+arr[4]]==0) 
			 {
			   flag=true;
			   break;	
			 }	
		  }
		  else if(i==3)
		  {
		  	if(vis[arr[2]+arr[4]]==0)
		  	{
		  	  flag=true;
				break;	
			}
		  }
		  else
		  {
		  	if(vis[arr[2]+arr[3]]==0)
		  	{
		  	  flag=true;
				break;	
			}
		  }	
	   }              
  }
	if(flag==false)
	{
		printf("wrong answer\n");
		printf("%d\n",k);
	}
}

int  main()
{
	
    int tt=0;
    ola(2000000);
   // printf("cnt:%d\n",cnt);
//	for(int i=1;i<=20;i++) printf("%d\n",prim[i]);  
    scanf("%d",&tt);
    while(tt--)
    {
    	int n;
		scanf("%d",&n);
		n*=2;
        for(int i=n;i>=1;i--)
		{
		   if(dis[i]) continue;
		   for(int j=n-1;j>=1;j--)
		   {
		     if(dis[j])	 continue;
		     if(vis[i+j]==0)
		     {
		     	printf("%d %d\n",i,j);
		     	dis[i]=1;
		     	dis[j]=1;
		     	break;
			 }
		   }	
		}
		for( int i=1;i<=n;i++)
		{
			if(dis[i]!=1)
			{
				///printf("wrong answer\n");
			 } 
			 dis[i]=0;
		}                	 	
	}
	return 0;
}
