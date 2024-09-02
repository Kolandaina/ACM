#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    char name[100];
    int a;
    int b;
    int c;
}x;
int main()
{
    int n;
    cin>>n;
    x f[1200];
    for(int i=0;i<n;i++)
    {
        cin>>f[i].name>>f[i].a>>f[i].b>>f[i].c;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n-i-1;j++)
        {
            if(f[j].a+f[j].b+f[j].c<f[j+1].a+f[j+1].b+f[j+1].c)
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
                
                char tt[100];
                strcpy(tt,f[j].name);
                strcpy(f[j].name,f[j+1].name);
                strcpy(f[j+1].name,tt);
            }
        }
    }
    cout<<f[0].name<<" "<<f[0].a<<" "<<f[0].b<<" "<<f[0].c;
    return 0;
}