#include<bits/stdc++.h>
using namespace std;
#define int long long
int node(int a)
{
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0) return 0;
    }
    return 1;
}
signed main()
{
    int n,s=0,m=0;
    cin>>n;
    if(n<2)
    {
		cout<<0<<endl;
		return 0;
	}
    else if(n==2)
    {
		cout<<2<<endl<<1<<endl;
		return 0;
    }
    for(int i=2;i<=n;i++)
    {
        if(s+i>n)
        {
            cout<<m<<endl;
            break;
        }
        if(node(i)!=0)
        {
            s+=i;
            m++;
            cout<<i<<endl;
        }
    }
    return 0;
}