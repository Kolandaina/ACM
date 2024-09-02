#include<bits/stdc++.h>
using namespace std;
int node(int a)
{
    int flag=1;
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        {
            flag=0;
            break;

        }
    }
    if(flag==1) return true;
    else return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(node(i))
        {
            cout<<i<<" ";
        }
    }
    return 0;
}