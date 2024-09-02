#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	cout<<(*max_element(a,a+4)+*min_element(a,a+4))*2-accumulate(a,a+4,0);
	return 0;
}