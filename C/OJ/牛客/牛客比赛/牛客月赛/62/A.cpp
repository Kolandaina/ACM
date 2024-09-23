#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	for(int k=0;k<q;k++)
	{
		int h[1001],n,a,x,b,m;
		cin>>n;
		for(int i=0;i<n;i++) cin>>h[i];
		cin>>a>>x>>b;
		cin>>m;
		
		for(int i=0;i<m-1;i++)
		{
			for(int j=0;j<n;j++)
			{
				int t=h[j];
				h[j]+=a;
			    if(h[j]>x)
			    {
					h[j]=b;
			    }
			}
		}
		for(int i=0;i<n;i++)
		{
			cout<<h[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}