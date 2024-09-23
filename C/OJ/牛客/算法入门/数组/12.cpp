#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n+1;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=0;i<n+1;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}