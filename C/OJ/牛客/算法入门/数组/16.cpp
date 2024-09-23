#include<bits/stdc++.h>
using namespace std;
int a[50][50];
int main()
{
    int n;
    cin>>n;
    a[1][1]=1;
    a[2][1]=1;
    a[2][2]=1;
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1) a[i][1]=1;
            if(j==i) a[i][i]=1;
            else a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}