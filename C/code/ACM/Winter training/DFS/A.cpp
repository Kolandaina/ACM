#include<bits/stdc++.h>
using namespace std;
#define int long long
int vis[10]={0},ans[10]={0},t;
void dfs(int x)
{
    if(x==t)
    {
        for(int i=0;i<x;i++)
        {
            printf("%5d",ans[i]);
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=t;i++)
    {
        if(vis[i]!=1)
        {
            vis[i]=1;
            ans[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
signed main()
{
    cin>>t;
    dfs(0);
}
