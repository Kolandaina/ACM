#include<bits/stdc++.h>
using namespace std;
int node(int a)
{
    int s=0;
    while(a!=0)
    {
        int b=a%10;
        if(b==2) s++;
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
        cnt+=node(i);
    }
    cout<<cnt;
    return 0;
}