#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	int t,n;
	string winner="Bob";
	cin>>t;
	while(t--)
	{
		winner="Bob";
		cin>>n;
		while(n)
		{
			if(n%2)
			{
				n--;
			}else{
				n/=2;
			}
			winner=(winner=="Bob")?"Alice":"Bob";
		}
		cout<<winner<<"\n";
	}
	cout<<endl;
	return 0;
}
