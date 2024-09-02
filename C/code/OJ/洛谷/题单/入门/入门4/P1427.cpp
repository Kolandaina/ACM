#include<bits/stdc++.h>
using namespace std;
int main()
{
    int o;
    int a[110];
    for(int i=0;i<110;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            o=i;
            break;
        }
    }
    for(int i=o-1;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}