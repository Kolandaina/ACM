#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a>b)
		{
			if(b==0) cout<<"1"<<endl;
			else cout<<b-1<<endl;	
		}
		else 
		{
			if(b==15) cout<<"14"<<endl;
			else cout<<b+1<<endl;
		}
	}
	return 0;
}