#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<*min_element(a+1,a+1+n)<<endl;
    return 0;
}