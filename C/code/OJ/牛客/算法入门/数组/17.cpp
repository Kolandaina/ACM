#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    cout<<a[x][y];
    return 0;
}