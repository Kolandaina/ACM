#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[3333];
    int b[10000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-m;i++)
    {
        int sum=0;
        for(int j=i;j<i+m;j++)
        {
            sum+=a[j];
        }
        b[i]=sum;
    }
    if(m==0) cout<<"0";
    else cout<<*min_element(b,b+n-m);
    return 0;
}
