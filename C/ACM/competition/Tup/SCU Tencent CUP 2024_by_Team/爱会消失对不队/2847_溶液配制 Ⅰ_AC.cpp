#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=100010,MOD = 1e9+7;
double a[N];
double tem;
int mi[N];
int main(){
	ll n,q;
	cin>>n>>q;
	tem = -1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tem = max(a[i],tem);
	}
	a[0] = -1;
	a[n+1] = tem+1;
	sort(a+1,a+1+n);
	mi[0]=1;
	for(int i=1;i<=1e5+1;i++){
		mi[i] = (mi[i-1]*2)%MOD;
	}
	while(q--){
		cin>>tem;
		ll x,y;
		if(tem<a[1]||tem>a[n])
		{
			cout<<0<<endl;
			continue;
		}
		
		ll l=0,r=n+1;
		while(l<r){
			int mid = l+r+1>>1;
			if(a[mid]<tem) l=mid;
			else r=mid-1;
		}
		x=l;
		l=0,r=n+1;
		while(l<r){
			int mid = l+r>>1;
			if(a[mid]>tem) r=mid;
			else l=mid+1;
		}
		y=l;
//		cout<<x<<' '<<y<<"===="<<endl;
		ll ans1 = ((mi[x]-1+MOD)%MOD)  * ((mi[n+1-y]-1+MOD)%MOD);
		ans1 %=MOD;
		
		ll ans2 = (((mi[y-x-1]-1+MOD)%MOD)*mi[x]%MOD)*mi[n+1-y]%MOD;
		ans2%=MOD;
		cout<<(ans1+ans2)%MOD<<endl;
		
		
		
	}
	return 0;
}
