#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1000;
const int mod=1000000007;
int p,q,a1,a2,n,m;
int w[N][N],ans[N][N],c[N][N],f[N][N];


void mul(int a[N][N],int b[N][N],int x)
{
    memset(c,0,sizeof(c));
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            for(int k=1;k<=2;k++)
            {
                c[i][j]+=a[i][k]*b[k][j]%x;
            }
        }
    }
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            a[i][j]=c[i][j]%x;
        }
    }
}
void node(int a[N][N],int k,int y)
{
    for(int i=1;i<=10;i++) ans[i][i]=1;
    while(k)
    {
        if(k&1) mul(ans,a,y);
        mul(a,a,y);
        k>>=1;
    }
}
signed main()
{
    cin>>p>>q>>a1>>a2>>n>>m;
    w[1][1]=p;
    w[2][1]=q;
    w[1][2]=1;
    w[2][2]=0;
    f[1][1]=a1;
    f[1][2]=a2;
    if(n==1) cout<<a1%m;
    else if(n==2) cout<<a2%m;
    else
    {
        node(w,n-1,m);
        mul(ans,f,m);
        cout<<ans[1][1];
    }
    return 0;
}