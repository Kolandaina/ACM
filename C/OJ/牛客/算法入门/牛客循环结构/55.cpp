#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,k;
	cin>>a>>b; 
	if(a>b) swap(a, b);
	while(b)
    {
		k=b;
		b=a%b;
		a=k;
	}
	cout<<k;
	return 0;
}