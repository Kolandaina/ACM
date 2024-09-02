#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    int n,m;
    cin>>n>>m;
    n+=m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}