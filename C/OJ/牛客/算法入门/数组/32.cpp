#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int n;
    int a;
    int b;
    int c;
}x;
int main()
{
    int m;
    cin>>m;
    x f[1000];
    for(int i=1;i<=m;i++)
    {
        cin>>f[i].a>>f[i].b>>f[i].c;
        f[i].n=i;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m-i;j++)
        {
            if(f[j].a+f[j].b+f[j].c<f[j+1].a+f[j+1].b+f[j+1].c)
            {
                int nn=f[j].n;
                f[j].n=f[j+1].n;
                f[j+1].n=nn;

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
            if(f[j].a+f[j].b+f[j].c==f[j+1].a+f[j+1].b+f[j+1].c)
            {
                if(f[j].n>f[j+1].n)
                {
                    int nn=f[j].n;
                    f[j].n=f[j+1].n;
                    f[j+1].n=nn;

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
    }
    for(int i=1 ;i<=5;i++)
    {
        cout<<f[i].n<<" "<<f[i].a+f[i].b+f[i].c<<endl;
    }
    cout<<258-88-99;
    return 0;
}