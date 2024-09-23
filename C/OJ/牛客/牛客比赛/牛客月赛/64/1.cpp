#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,a,b;
    cin>>n>>k>>a>>b;
	int x=a*(n-1);
	int y=(k-1+n-1)*b;
	if (x>y)
    {
        cout<<1;
    }
	else if(x==y)
    {
        cout<<0;
    }
	else cout<<2;
	return 0;
}