#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n[3];
    for(int i=0;i<3;i++) cin>>n[i];
    sort(n,n+3);
    cout<<n[0]<<"/"<<n[2];
    return 0;
}