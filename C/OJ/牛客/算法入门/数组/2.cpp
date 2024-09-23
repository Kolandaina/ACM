#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,s,sum=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        s=i;
        while(s)
        {
            if(s%10==x)
            {
                sum++;
            }
            s/=10;
        }
    }
    cout<<sum;
    return 0;
}