#include<bits/stdc++.h>
using namespace std;
#define int long long


const int N=1000;
const int mod=1000000007;
int n,k;
int p[N][N],ans[N][N],c[N][N];


void mul(int a[N][N],int b[N][N])
{
    memset(c,0,sizeof c);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j]%mod;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=c[i][j]%mod;
        }
    }
}
void pow(int a[N][N],int k)
{
    for(int i=1;i<=n;i++) ans[i][i]=1;
    while(k)
    {
        if(k&1) mul(ans,a);
        mul(a,a);
        k>>=1;
    }   
}
signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>p[i][j];
        }
    }
    pow(p,k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<ans[i][j]%mod<<" ";
        }
        cout<<endl;
    }
    return 0;
}