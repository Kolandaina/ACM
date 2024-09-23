#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m[100000];
	for(int i=1;i<=n;i++) cin>>m[i];
	int x;
	cin>>x;
	int l=0,r=n;
	while(r>=l)
	{
		int mid=(r+l)/2;
		if(m[mid]<x) l=mid+1;
		else if(m[mid]<x) r=mid-1;
		else
		{
			cout<<mid-1;
			break;
		}
	}
	if(l>r)
	{
		cout<<"no answer";
	}
	return 0;
}