#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef struct node
{
    int a;
    int b;
    int c;
    int d;
}x;
signed main()
{
    int n;
    cin>>n;
    x f[10000];
    for(int i=1;i<=n;i++)
    {
        cin>>f[i].a>>f[i].b>>f[i].c;
        f[i].d=f[i].a*3600+f[i].b*60+f[i].c;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(f[i].d>f[i+1].d)
            {
                int aa=f[i].a;
                f[i].a=f[i+1].a;
                f[i+1].a=aa;

                int bb=f[i].b;
                f[i].b=f[i+1].b;
                f[i+1].b=bb;

                int cc=f[i].c;
                f[i].c=f[i+1].c;
                f[i+1].c=cc;

                int dd=f[i].d;
                f[i].d=f[i+1].d;
                f[i+1].d=dd;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<f[i].a<<" "<<f[i].b<<" "<<f[i].c<<endl;
    }
    return 0;
}