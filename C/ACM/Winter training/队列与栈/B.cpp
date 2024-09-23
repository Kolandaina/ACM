#include<stdio.h>
#include<string.h>
int main()
{
    char a[1200];
    while (scanf("%s",&a)!=EOF)
    {
        int n=strlen(a);
        int s=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='(') s++;
            else if(a[i]==')') s--;
            else if(a[i]=='B') break;
        }
        printf("%d\n",s);
    }
    return 0;
}