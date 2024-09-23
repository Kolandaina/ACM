#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    int flag=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[i][j]!=0)
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    if(flag==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}