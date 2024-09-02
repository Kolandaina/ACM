#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,aa[10000],s=0;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        aa[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int j=a;j<b;j++)
        {
            aa[j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        s+=aa[i];
    }
    cout<<s-1;
    return 0;
}