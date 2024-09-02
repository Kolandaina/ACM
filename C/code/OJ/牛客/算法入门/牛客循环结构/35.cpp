#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a[10000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    n=unique(a,a+n)-a;
    cout<<a[n-1]-a[n-2]<<" "<<a[n-1]-a[1]<<" "<<a[n-2]-a[1]<<" "<<a[n-2]-a[0]<<endl;
    return 0;     
}