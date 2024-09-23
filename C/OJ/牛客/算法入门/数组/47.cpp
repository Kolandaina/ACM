#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char x[1000];
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        char q,w;
        cin>>q>>w;
        for(int j=a;j<=b;j++)
        {
            if(x[j]==q) x[j]=w;
        }
    }
    for(int i=1;i<=n;i++) cout<<x[i];
    return 0;
}