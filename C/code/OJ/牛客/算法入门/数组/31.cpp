#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int a;
    int b;
}x;
int main()
{
    int n,m;
    cin>>n>>m;
    x f[10000];
    m=1.0*m*1.5;
    for(int i=1;i<=n;i++) cin>>f[i].a>>f[i].b;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(f[j].b<f[j+1].b)
            {
                int aa=f[j].a;
                f[j].a=f[j+1].a;
                f[j+1].a=aa;

                int bb=f[j].b;
                f[j].b=f[j+1].b;
                f[j+1].b=bb;
            }
            if(f[j].b==f[j+1].b && f[j].a>f[j+1].a)
            {
                int aa=f[j].a;
                f[j].a=f[j+1].a;
                f[j+1].a=aa;
            }
        }
    }
    while(f[m].b==f[m+1].b) m++;
    cout<<f[m].b<<" "<<m<<endl;
    for(int i=1;i<=m;i++) cout<<f[i].a<<" "<<f[i].b<<endl;
    return 0;
}