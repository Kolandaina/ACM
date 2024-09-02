#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10];
    for(int i=1;i<=10;i++) cin>>a[i];
    int b;
    cin>>b;
    int s=0;
    for(int i=1;i<=10;i++)
    {
        if(a[i]<=b+30) s++;
    }
    cout<<s;
    return 0;
}