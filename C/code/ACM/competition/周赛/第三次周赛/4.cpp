#include<bits/stdc++.h>
using namespace std;
int m[100000];
int main()
{
	int n,k;
	cin>>n>>k;
	long long s=0;
	for(int i=0;i<n;i++)
	{
	    cin>>m[i];
	    s+=m[i];
	}
	cout<<s;
	return 0;
}