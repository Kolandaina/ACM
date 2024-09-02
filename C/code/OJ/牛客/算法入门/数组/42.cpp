#include<bits/stdc++.h>
using namespace std;
char a[20];
int main()
{
    scanf("%s",a);
    int n=strlen(a);
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
        if((i+1)%3==0&&i!=n-1) cout<<",";
    }
    return 0;
}