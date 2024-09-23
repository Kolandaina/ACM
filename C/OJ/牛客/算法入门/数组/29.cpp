#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int ans=unique(a,a+n)-a;
    cout<<ans<<endl;
    for(int i=0;i<ans;i++) cout<<a[i]<<" ";
    return 0;
}