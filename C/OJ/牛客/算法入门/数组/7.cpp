#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j=i;j<n;j++)
        {
            if(a[j]>a[i])
            {
                a[i]=j+1;
                flag=1;
                break;
            }
        }
        if(flag==0) a[i]=0;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}