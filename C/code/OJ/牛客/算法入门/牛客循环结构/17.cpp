#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%4==0) continue;
		if(i/10000!=4 && i/1000%10!=4 && i/100%10!=4 && i/10%10!=4 && i%10!=4)
		{
		    cout<<i<<"\n";
		}
	}
	return 0;
}