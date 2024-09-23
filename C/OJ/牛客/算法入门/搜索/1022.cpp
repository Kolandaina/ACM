#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char a[505][505];
int vis[505][505];
int dis[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m,t=0;
void dfs(int x,int y)
{
    if(a[x][y]=='E')
    {
        t = 1;
        return;
    }
    for(int i = 0;i < 4;i++)
    {
        int dx = x + dis[i][0];
        int dy = y + dis[i][1];
        if(vis[dx][dy] == 0 && a[dx][dy] != '#'&&dx >=1 &&dx <= n && dy >= 1 && dy <= m)
        {
            vis[dx][dy] = 1;
            dfs(dx,dy);
        }
    }

}
int main()
{
    while(cin >> n >> m)
    {
        int sx,sy;
        t = 0;
        memset(vis, 0, sizeof (vis));
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 'S')
                    sx = i,sy = j;
            }
        }
        dfs(sx,sy);
        if(t)
        {
            cout <<"Yes"<< "\n";
        }
        else
        {
            cout << "No"<<"\n";
        }

    }
    return 0;
}
