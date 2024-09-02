#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m[10];
	int a,b=0;
	for(int i=0;i<10;i++) cin>>m[i];
	cin>>a;
	for(int i=0;i<10;i++)
	{
		if(a+30>=m[i]) b++;
	}
	cout<<b;
	return 0;
}