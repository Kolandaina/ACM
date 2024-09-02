#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int a;
    int b;
    int c;
}x;
int main()
{
    int n;
    x f[100];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i].a>>f[i].b;
        f[i].c=f[i].a*f[i].a+f[i].b*f[i].b;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(f[j].a>f[j+1].a)
            {
                int aa=f[j].a;
                f[j].a=f[j+1].a;
                f[j+1].a=aa;

                int bb=f[j].b;
                f[j].b=f[j+1].b;
                f[j+1].b=bb;

                int cc=f[j].c;
                f[j].c=f[j+1].c;
                f[j+1].c=cc;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<f[i].a<<" "<<f[i].b<<" "<<f[i].c<<endl;
    return 0;
}