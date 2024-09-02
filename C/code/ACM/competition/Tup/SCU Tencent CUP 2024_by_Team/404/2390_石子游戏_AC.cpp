#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n;
	string winner="Bob";
	cin>>t;
	while(t--)
	{
		int cnt=0;
		winner="Bob";
		cin>>n;
		if(n>=4)
		{
			if(n%2==0) cout<<"Alice"<<"\n";
			else cout<<"Bob"<<"\n";
		}
		else if(n==3||n==1)
		{
			cout<<"Alice"<<"\n";
		}
		else if(n==2)cout<<"Bob"<<"\n";
		
	}
	cout<<endl;
	return 0;
}
