#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,dx,dy;
int vis[N],r_line[N<<1],l_line[N<<1],ans[N];
void dfs(int cnt)
{
    if(cnt==n+1)
    {
        m++;
        if(m<=3)
        {
            for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0&&r_line[cnt+i]==0&&l_line[cnt-i+N]==0)
        {
            vis[i]=1;
            r_line[cnt+i]=1;
            l_line[cnt-i+N]=1;
            ans[cnt]=i;
            dfs(cnt+1);
            vis[i]=0;
            r_line[cnt+i]=0;
            l_line[cnt-i+N]=0;
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    cout<<m;
    return 0;
}