#include<stdio.h>
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            for(int k=0;k<n-1-i;k++)
            {
                printf(" ");
            }
            for(int t=0;t<2*i+1;t++)
            {
                printf("*");
            }
            printf("\n");
        }
        for(i=0;i<n-1;i++)
        {
            for(int a=0;a<i+1;a++)
            {
                printf(" ");
            }
            for(int b=0;b<2*(n-1-i)-1;b++)
            {
                printf("*");
            }
            printf("\n");
        }
	}
    return 0;
}
