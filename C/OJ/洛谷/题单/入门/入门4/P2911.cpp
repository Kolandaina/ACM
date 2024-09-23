#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    int s1,s2,s3;
    cin>>s1>>s2>>s3;
    for(int i=1;i<=s1;i++)
    {
        for(int j=1;j<=s2;j++)
        {
            for(int k=1;k<=s3;k++)
            {
                a[i+j+k]++;
            }
        }
    }
    int s=*max_element(a,a+s1+s2+s3-2);
    for(int i=3;i<=s1+s2+s3;i++)
    {
        if(s==a[i])
        {
            cout<<i;
            break;
        }
    }
    return 0;
}