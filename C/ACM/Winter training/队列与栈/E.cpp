#include<iostream>
using namespace std;
int a[100000];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(m--)
    {
        int hh=1,tt=n;
		int b,t=n;
        cin>>b;
        while (t--)
        {
            if(a[hh]!=b)
            {
                a[++tt]=a[hh++];
            }
            else
            {
                hh++;
            }
        }
        a[--hh]=b;
		for(int i=1;i<=n;i++) a[i]=a[hh++];
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}