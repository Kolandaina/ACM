#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int cnt=unique(a,a+n)-a;
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++) cout<<a[i]<<" ";
    return 0;
}