#include<stdio.h>
int digit(int n,int k)
{
 int i,t;
 for(i=1;i<=k;i++)
    {
     t= n%10;
     n=n/10;
    }
    return t;
}
int main()
{
 int n,k,t;
 scanf("%d%d",&n,&k);
 t=digit(n,k);
 printf("%d",t);
}
