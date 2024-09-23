#include<bits/stdc++.h>
using namespace std;
long long i[100010],j[100010];
int main()
{
    int a,b;
    long long x=0,y=0;
    long long sum1=0,sum2=0,sum;
    cin>>a>>b;
    while(a>0)
    {
        i[x]=a%2;
        x++;
        a=a/2;
    }
    while(b>0)
    {
        j[y]=b%2;
        y++;
        b=b/2;
    }
    for(int x=10000;x>=0;x--) sum1=sum1*10+i[x];
    for(int y=10000;y>=0;y--) sum2=sum2*10+j[y];
    sum=sum1+sum2;
    cout<<sum<<endl;
    return 0;
}