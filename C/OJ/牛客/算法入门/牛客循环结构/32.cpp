#include<bits/stdc++.h>
using namespace std;
int m[100000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m[i];
	}
	cout<<*max_element(m,m+n)-*min_element(m,m+n);
	return 0;
}