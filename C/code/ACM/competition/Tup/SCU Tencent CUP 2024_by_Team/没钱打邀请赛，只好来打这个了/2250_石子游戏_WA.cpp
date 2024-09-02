#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n%2==0)
		{
			if((n/2)%2==1)
			{
				cout<<"Bob"<<endl;
			}
			else
			{
				cout<<"Alice"<<endl;
			}
		}
		else
		{
			if((n-1)/2%2==0)
			{
				cout<<"Alice"<<endl;
			}
			else
			{
				cout<<"Bob"<<endl;
			}
		}
	}
	return 0;
}
