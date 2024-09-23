#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int s=0;
    for(int i=n;i>0;i--)
    {
        int x=i;
        while(x!=0)
        {
            int y=x%10;
            if(y==k) s++;
            x/=10;
        }
    }
    cout<<s<<endl;
    return 0;
}