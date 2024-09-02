#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s=0,days=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            s+=i;
            days++;
            if(days==n) break;
        }
        if(days==n) break;
    }
    cout<<s;
    return 0;
}