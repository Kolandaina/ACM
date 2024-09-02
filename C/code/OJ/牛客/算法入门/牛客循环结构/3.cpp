#include<stdio.h>
int main()
{
    char n;
    int i,j;
    scanf("%c",&n);
    int c=n-'A'+1;
    for(i=0;i<c;i++)
    {
        for(j=1;j<c-i;j++)
        {
            printf(" ");
        }
        for(j=0;j<i;j++)
        {
        	printf("%c",'A'+j);
		}
        for(j=i;j>=0;j--)
        {
        	printf("%c",'A'+j);
		}   
        printf("\n");
    }
    return 0;
}