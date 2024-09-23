#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int ans[100],vis[100];
void dfs(int cnt)
{
    if(cnt>=m+1)
    {
        for(int i=1;i<=m;i++)
        {
            printf("%3d",ans[i]);
        }
        cout<<endl;
        return ;
    }
    for(int i=ans[cnt-1]+1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            ans[cnt]=i;
            dfs(cnt+1);
            vis[i]=0;
        }
    }
}
signed main()
{
    cin>>n>>m;
    dfs(1);
}