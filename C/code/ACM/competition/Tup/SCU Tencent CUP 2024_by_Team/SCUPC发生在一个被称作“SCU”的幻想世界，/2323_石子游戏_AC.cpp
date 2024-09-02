#include <bits/stdc++.h>
using namespace std;

#define int long long
int t,n;
const int N = 1e6 + 10;
int ans[10000001];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	ans[1]=1;
	ans[2]=2;
	for(int i=3;i<=1e6;i++)
	{
		if(i%2==1)
		{
			ans[i]=ans[i-1];
			if(ans[i]==1)ans[i]=2;
			else ans[i]=1;
		}
		else
		{
			ans[i]=2;
			if(ans[i-1]==2)ans[i]=1;
			if(ans[i/2]==2)ans[i]=1;
		}
	}
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(ans[n]==1)cout<<"Alice"<<endl;
		if(ans[n]==2)cout<<"Bob"<<endl;
	}
	return 0;
}
