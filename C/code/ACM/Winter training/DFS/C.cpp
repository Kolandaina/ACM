#include<bits/stdc++.h>
using namespace std;
int n,m;
char res[100][100];
void dfs(int x,int y)
{
    if(x<1||y<1||x>n||y>m||res[x][y]=='0')
    {
        return ;
    }
    res[x][y]='0';
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>res[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(res[i][j]!='0')
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}