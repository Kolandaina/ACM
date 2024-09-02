#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1200][3];
    int b[1200];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
        }
        b[i]=a[i][3]+a[i][1]+a[i][2];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if((abs(a[i][1]-a[j][1])<=5&&abs(a[i][2]-a[j][2])<=5&&abs(a[i][3]-a[j][3])<=5&&abs(b[i]-b[j])<=10))
            {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}