#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int aa[10000];
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
	}
	while(m--)
	{
		int x;
		cin>>x;
		int r=n,l=1,mid;
		while(r>l)
		{
			mid=(r+l)/2;
			if(aa[mid]<x) l=mid+1;
			else r=mid;
		}
		if(aa[r]!=x)
		{
			cout<<"-1 -1"<<endl;
			continue;
		}
		cout<<r-1<<" ";
		r=n,l=1;
		while(r>l)
		{
			mid=(r+l+1)/2;
			if(aa[mid]<=x) l=mid;
			else r=mid-1;
		}
		cout<<l-1<<endl;
	}
	return 0;
}