#include<bits/stdc++.h>
using namespace std;
int node(int b)
{
    int s=(int)sqrt(b);
    if(b==s*s) return 1;
    else return 0;
}
int main()
{
    int n;
    int a[1000];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
    {
        if(node(a[i])==0)
        {
            cout<<a[i];
            break;
        }
    }
    return 0;
}