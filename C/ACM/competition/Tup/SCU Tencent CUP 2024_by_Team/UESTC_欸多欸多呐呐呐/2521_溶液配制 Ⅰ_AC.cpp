#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int mod=1e9+7;
int point[maxn],pw[maxn];
map<int,int>mp;
int main() {
	int n,m;
	cin>>n>>m;
	pw[0]=1;
	for(int i=1;i<=n;i++)
	{
		pw[i]=pw[i-1]*1ll*2%mod;
		int t1,t2;
		scanf("%d.%d",&t1,&t2);
		point[i]=t1*1000+t2;
		mp[point[i]]++;
	}
	sort(point+1,point+1+n);
	while(m--)
	{
		int t1,t2;
		scanf("%d.%d",&t1,&t2);
		int y=t1*1000+t2;
		//cout<<y<<endl;
		int pos=lower_bound(point+1,point+1+n,y)-point;			
	//	cout<<pos<<endl;
		if(point[pos]==y)
		{
			int t=mp[y];
			cout<<((pw[pos-1]-1)*1ll*(pw[n-pos-t+1]-1)%mod+(pw[t]-1)*1ll*pw[n-t]%mod)%mod<<endl;
		}
		else 
		{
			cout<<(pw[pos-1]-1)*1ll*(pw[n-pos+1]-1)%mod<<endl;
		}
	}
	return 0;
}

