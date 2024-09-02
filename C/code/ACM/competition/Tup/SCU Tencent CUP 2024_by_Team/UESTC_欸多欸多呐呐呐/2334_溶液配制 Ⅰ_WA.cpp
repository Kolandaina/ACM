#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int mod=1e9+7;
int point[maxn],pw[maxn];
map<int,int>mp;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	pw[0]=1;
	for(int i=1;i<=n;i++)
	{
		pw[i]=pw[i-1]*1ll*2%mod;
		double x;
		cin>>x;
		point[i]=x*1000;
		mp[point[i]]++;
	}
	sort(point+1,point+1+n);
	while(m--)
	{
		double x;
		cin>>x;
		int y=x*1000;
		//cout<<y<<endl;
		int pos=lower_bound(point+1,point+1+n,y)-point;			
	//	cout<<pos<<endl;
		if(point[pos]==y)
		{
			int t=mp[y];
			printf("%d\n",((pw[pos-1]-1)*1ll*(pw[n-pos-t+1]-1)%mod+(pw[t]-1)*1ll*pw[n-t]%mod)%mod);
		}
		else 
		{
			printf("%d\n",(pw[pos-1]-1)*1ll*(pw[n-pos+1]-1)%mod);
		}
	}
	return 0;
}

