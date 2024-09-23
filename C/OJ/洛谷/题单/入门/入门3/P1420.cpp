#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[1000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int b=0;
        for(int j=i;j<=n;j++)
        {
            if(a[j]==a[j+1]-1)
            {
                b++;
                if(cnt<=b) cnt=b;
            }
            else break;
        }
    }
    cout<<cnt+1<<endl;
    return 0;
}