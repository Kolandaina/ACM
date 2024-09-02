#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long a,b,c;
		cin>>a>>b>>c;
		if(a==max(a,max(b,c))) cout<<"NO"<<"\n";
		else cout<<"YES"<<"\n";
	}
	return 0;
}