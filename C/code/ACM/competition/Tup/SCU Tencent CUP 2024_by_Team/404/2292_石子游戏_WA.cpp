#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		int cnt=0;
		//winner="Bob";
		cin>>n;
		while(n)
		{
			if(n%2)
			{
				n--;
			}else{
				n/=2;
			}
			//winner=(winner=="Bob")?"Alice":"Bob";
			//cout<<n<<endl;
			cnt++;
		}
		if(cnt%2)
		{
			cout<<"Alice"<<"\n";
		}else{
			cout<<"Bob"<<"\n";
		}
		//cout<<winner<<"\n";
	}
	cout<<endl;
	return 0;
}
