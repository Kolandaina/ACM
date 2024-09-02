#include<bits/stdc++.h>
using namespace std;
char a[100][100];
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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='?')
            {
                int s=0;
                if(a[i-1][j]=='*') s++;
                if(a[i+1][j]=='*') s++;
                if(a[i][j-1]=='*') s++;
                if(a[i][j+1]=='*') s++;
                if(a[i+1][j+1]=='*') s++;
                if(a[i-1][j-1]=='*') s++;
                if(a[i-1][j+1]=='*') s++;
                if(a[i+1][j-1]=='*') s++;
                a[i][j]=s+48;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}