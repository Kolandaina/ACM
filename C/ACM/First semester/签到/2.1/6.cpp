#include<bits/stdc++.h>
using namespace std;
int node(int a,int b)
{
    int x,y;
    x=a%10;
    y=b/10%10;
    a/=10;
    b%=10;
    a=a*10+y;
    b=x*10+b;
    if(a<=23&&a>=0&&b<=59&&b>=0) return 1;
    else return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int s=m;
    for(int i=n;i<=23;i++)
    {
        for(int j=0;j<=59;j++)
        {
            if(node(i,s)==1)
            {
                cout<<i<<" "<<s<<endl;
                return 0;
            }
            s++;
            if(s==60) s=0;
        }
    }
    return 0;
}