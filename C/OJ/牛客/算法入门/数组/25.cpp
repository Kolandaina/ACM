#include<bits/stdc++.h>
using namespace std;
int aa[10][10];
int main()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cin>>aa[i][j];
        }
    }
    int flag=1;
    for(int i=1;i<=9;i++)
    {
        int s=0;
        for(int j=1;j<=9;j++)
        {
            s+=aa[i][j];
        }
        if(s!=45)
        {
            flag=0;
        }
    }
    for(int j=1;j<=9;j++)
    {
        int s=0;
        for(int i=1;i<=9;i++)
        {
            s+=aa[i][j];
        }
        if(s!=45)
        {
            flag=0;
        }
    }
    
    if(flag==0) cout<<"NO";
    else cout<<"YES";
    return 0;
}