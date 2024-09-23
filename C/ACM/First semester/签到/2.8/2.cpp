#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int b=unique(a,a+n)-a;
    if(b<2) cout<<"NO";
    else cout<<a[1];
    return 0;
}