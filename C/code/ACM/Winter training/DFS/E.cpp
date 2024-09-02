#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t;
int ans[100],vis[100],a[100],b[100],c[100];
int node(int x)
{
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}
void dfs(int cnt)
{
    if(cnt>=m+1)
    {
        for(int i=1;i<=m;i++)
        {
            c[t]+=b[i];
        }
        t++;
        return ;
    }
    for(int i=ans[cnt-1]+1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            ans[cnt]=i;
            b[cnt]=a[i];
            dfs(cnt+1);
            vis[i]=0;
        }
    }
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    int s=0;
    for(int i=0;i<t;i++)
    {
        s+=node(c[i]);
    }
    cout<<s<<endl;
    return 0;
}