#include<bits/stdc++.h>
using namespace std;
int aa[200000];
void init()
{
    for(int i=0;i<=31622;i++)
    {
        aa[i]=i*i;
    }
}
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)
    {
        int l=0,r=31622,mid,x,y;
		cin>>x>>y;
		while(r>l)
		{
			mid=(r+l)/2;
			if(aa[mid]<x) l=mid+1;
			else r=mid;
		}
        int temp=r;
        l=0,r=31622;
        while(r>l)
        {
            mid=(r+l+1)/2;
            if(aa[mid]<=y) l=mid;
            else r=mid-1;
        }
        cout<<r-temp+1<<endl;
    }
    return 0;
}