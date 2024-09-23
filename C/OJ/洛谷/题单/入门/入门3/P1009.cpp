#include<bits/stdc++.h>
using namespace std;
#define int long long
int node(int a)
{
    int b=1;
    for(int i=1;i<=a;i++)
    {
        b*=i;
    }
    return b;
}
signed main()
{
    int n;
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        s+=node(i);
    }
    cout<<s;
    return 0;
}