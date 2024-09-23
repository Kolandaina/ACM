#include<stdio.h>
int set(int m,int n)
{
    if(m==0||n==1)
        return 1; 
    if(n>m)
        return set(m,m);
    else
        return set(m,n-1)+set(m-n,n);
}
int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        printf("%d\n",set(m,n));
    }
}
