#include<bits/stdc++.h>
using namespace std;
int m[7];
int n[7];
int a[10];
int main()
{
    int x;
    cin>>x;
    for(int i=0;i<7;i++)
    {
        cin>>m[i];
    }
    while(x--)
    {
        for(int i=0; i<7; i++)
        {
            cin>>a[i];
        }
        int s=0;
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<7;j++)
            {
                if(a[i]==m[j])
                {
                    s++;
                }
            }
        }
        n[s]++;
    }
    for(int i=7;i>=1;i--)
    {
        cout<<n[i]<<" ";
    }
    return 0;
}