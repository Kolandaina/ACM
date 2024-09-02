#include<bits/stdc++.h>
using namespace std;
int node(int a)
{
    int s=0;
    while(a!=0)
    {
        s+=a%10;
        a=a/10;
    }
    return s;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=n;i<=m;i++)
    {
        if(node(i)%5==0) cnt++;
    }
    cout<<cnt;
    return 0;
}