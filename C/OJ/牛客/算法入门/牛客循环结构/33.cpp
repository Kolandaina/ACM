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
	printf("%.2f ",accumulate(m,m+n,0)/n*1.0);
	cout<<*max_element(m,m+n)<<" "<<*min_element(m,m+n);
	return 0;
}