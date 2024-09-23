#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    double a=0,a1,b=0,b1;
    for(int  i=1;i<=n;i++)
    {
        if(i%k==0)
        {
            a+=i;
            a1++;
        }
        else
        {
            b+=i;
            b1++;
        }
    }
    printf("%.1f ",a/a1);
    printf("%.1f",b/b1);
    return 0;
}