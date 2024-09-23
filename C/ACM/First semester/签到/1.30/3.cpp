#include<bits/stdc++.h>
using namespace std;
const int a[]={1,2,3,4,5,6};
int t,n,s,r;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,s,r;
		cin>>n>>s>>r;
		int a=s-r;
		cout<<a<<' ';
		while(r)
		{
			if(r>=a && r-a>=n-2)
			{
				cout<<a<<' ';
				r-=a;
				n--;
			}
			else a--;
		}
		cout<<endl;
	}
	return 0;
}