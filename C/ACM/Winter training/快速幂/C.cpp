#include<bits/stdc++.h>
using namespace std;
#define int long long
int node(int a, int b)
{
    int res=1;
    a=a%10;
    while(b)
    {
        if(b&1) res=res*a%10;
        a=a*a%10;
        b>>=1;
    }
    return res;
}
signed main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        int s=node(a,b);
        cout<<s<<endl;
    }
    return 0;
}
