#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	for(int k=0;k<q;k++)
	{
		int n,m[1000],o=1,s;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>m[i];
		}
		while(1)
		{
			s=0;
			for(int i=0;i<n;i++)
			{
				if(m[i]>=o)
				{
					s++;
				}
			}
			if(s<o)
			{
				break;
			}
			o++;
		}
		cout<<o-1<<"\n";
	}
	return 0;
}