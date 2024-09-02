#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;scanf("%d",&n);
		if(n==1||n==3)puts("Alice");
		else if(n==2)puts("Bob");
		else if(n%2==0)puts("Alice");
		else puts("Bob");
	}
}
