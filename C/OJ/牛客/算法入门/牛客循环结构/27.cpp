#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	int m,n;
	for(int k=0;k<q;k++)
	{
		
		cin>>m>>n;
		int a[100];
		for(int i=0;i<n;i++) cin>>a[i];
		int i;
		if(m<a[0])
		{
			cout<<"0";
			continue;
	    }
		for(i=0;i<n;i++)
		{
			m-=a[i];
			if(m<=0)
			{
				break;
			}
		}
		
		cout<<i+1<<"\n";
	}
	return 0;
}