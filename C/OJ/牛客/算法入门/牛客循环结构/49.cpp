#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		if(i%3==2&&i%5==3&&i%7==2) cout<<i<<endl;
	}
	return 0;
}