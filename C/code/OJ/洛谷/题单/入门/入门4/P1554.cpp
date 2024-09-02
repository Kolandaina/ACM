#include<bits/stdc++.h>
using namespace std;
int q[10];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=n;i<=m;i++)
    {
        int a=i;
        while(a!=0)
        {
            int b=a%10;
            a/=10;
            q[b]++;
        }
    }
    for(int i=0;i<10;i++)
    {
        cout<<q[i]<<" ";
    }
    cout<<"\n";
    return 0;
}