#include<bits/stdc++.h>
using namespace std;
int a[2000001],n;
double x,y;
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        for(double i=1;i<=y;i++)
        {
            if(a[int(x*i)]==0) a[int(x*i)]=1;
            else a[int(i*x)]=0;
        }
    }
    for(int i=1;;i++)
    {
        if(a[i]==1)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}