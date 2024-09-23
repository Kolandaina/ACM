#include<bits/stdc++.h>
using namespace std;
int aa[1000];
int main()
{
    int n,m,s=0,b;
    cin>>n>>m;
    for(int j=0;j<n;j++)
    {
        int a;
        cin>>a;
        for(int i=0;i<a;i++)
        {
            cin>>b;
            aa[b]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(aa[i]==n) s++;
    }
    cout<<s;
    return 0;
}