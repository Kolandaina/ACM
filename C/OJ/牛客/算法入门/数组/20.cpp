#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main()
{
    int n,m,T,q,w,e;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        while(m--)
        {
            cin>>q>>w>>e;
            if(q==1)
            {
                for(int i=1;i<=n;i++)
                {
                    a[w][i]=e;
                }
            }
            else
            {
                for(int i=1;i<=n;i++)
                {
                    a[i][w]=e;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}