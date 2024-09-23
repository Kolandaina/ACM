#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin>>n;
    int a=1,b=1,c;
    if(n==0)
    {
        cout<<"0.00"<<endl;
        return 0;
    }
    if(n==1||n==2)
    {
        cout<<"1.00"<<endl;
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        c=a+b;
        b=a;
        a=c;
    }
    cout<<c<<".00"<<endl;
    return 0;
}