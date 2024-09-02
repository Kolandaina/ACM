#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,n;
    scanf("%d%d",&k,&n);
    int a[10];
    int o=0;
    while(n!=0)
    {
        a[o++]=n%2;
        n/=2;
    }
    long long ans=0;
    for (int i=o-1;i>=0;i--)
    {
        ans=ans*k+a[i];
    }
    cout<<ans<<endl;
    return 0;
}