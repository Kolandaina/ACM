#include<bits/stdc++.h>
using namespace std;
int main()
{
	int aa[10000];
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
	}
	while(m--)
	{
		cin>>x;
		int r=n,l=1,mid;
		while(r>=l)
		{
			mid=(l+r)/2;
			if(aa[mid]>x) r=mid-1;
			else if(aa[mid]==x)
			{
				cout<<mid<<endl;
				break;
			}
			else l=mid+1;
		}
	}
	return 0;
}