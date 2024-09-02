#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10];
    for(int i=1;i<=9;i++) cin>>a[i];
    if(a[1]==a[9]&&a[2]==a[8]&&a[3]==a[7]&&a[4]==a[6]) cout<<"YES";
    else cout<<"NO";
    return 0;
}