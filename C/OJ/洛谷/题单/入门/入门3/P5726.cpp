#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[1020];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    printf("%.2f",1.0*accumulate(a+1,a+n-1,0)/(n-2)*1.0);
    return 0;
}