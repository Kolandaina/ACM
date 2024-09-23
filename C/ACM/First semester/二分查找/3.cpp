#include<bits/stdc++.h>
using namespace std;
int aa[20000000];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>aa[i];
	while(m--)
	{
		int l=0,r=n-1,mid,x;
		cin>>x;
		while(r>l)
		{
			mid=(r+l)/2;
			if(aa[mid]<x) l=mid+1;
			else r=mid;
		}
		if(aa[r]!=x) cout<<"-1 ";
		else cout<<r+1<<" ";
	}
	return 0;
}