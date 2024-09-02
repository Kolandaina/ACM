#include<iostream>
using namespace std;
#define int long long
signed main()
{
    int a;
    cin>>a;
    if(a%2==0) cout<<a/2;
    else cout<<(a-1)/2-a;
    return 0;
}