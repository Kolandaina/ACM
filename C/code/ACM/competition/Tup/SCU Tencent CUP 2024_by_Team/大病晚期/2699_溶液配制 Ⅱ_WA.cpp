#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define push_back pb
const int N=2013;
const int mod=1e9+7;
struct P{
	ll x,y;
	P operator+(const P&a)const{return {x+a.x,y+a.y};}
	P operator-(const P&a)const{return {x-a.x,y-a.y};}
	ll operator*(const P&a)const{return x*a.x+y*a.y;}
	ll operator^(const P&a)const{return{x*a.y-y*a.x};}
	bool operator!=(const P&a)const{return x!=a.x||y!=a.y;}
	int lef(const P&a)const{
		int t=(*this)^a;
		return(t>0)-(t<0);
	}
};
bool cmp(P a,P b){
	return atan2l(a.y,a.x)<atan2l(b.y,b.x);
}
P a[N];
P b[N];
ll pw[N];
void solve(){
	int n,q;
	cin>>n>>q;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		int v=0;
		for(auto c:s)if(isdigit(c))v=v*10+c-48;
		a[i].x=v;
		v=0;
		cin>>s;
		for(auto c:s)if(isdigit(c))v=v*10+c-48;
		a[i].y=v;
	}
	while(q--){
		P p;
		cin>>s;
		int v=0;
		for(auto c:s)if(isdigit(c))v=v*10+c-48;
		p.x=v;
		v=0;
		cin>>s;
		for(auto c:s)if(isdigit(c))v=v*10+c-48;
		p.y=v;
		int tot=0;
		for(int i=1;i<=n;i++)if(a[i]!=p)b[++tot]=a[i]-p;
		ll ans=pw[n]-1;
		if(tot==0){
			cout<<ans<<'\n';
			continue;
		}
		sort(b+1,b+tot+1,cmp);
		for(int i=tot+1;i<=tot+tot;i++)b[i]=b[i-tot];
		for(int L=1,R=1;L <=tot;L++){
			if(L>1&&b[L].lef(b[L-1])==0&&b[L]*b[L-1]>0)continue;
			if(R<L)R=L;
			int f0=0,f1=0;
			int cnt=0;
			int P=L;
			while(!f0&&R+1<=L+tot){
				cnt++,R++,P++;
				if(b[L].lef(b[R])!=0||b[L].lef(b[R])==0&&b[L]*b[R]<0)f0=1;
			}
			R--,P--;
			int cnt2=0;
			while(!f1&&R+1<=L+tot){
				R++;
				if(b[L].lef(b[R])==-1||b[L].lef(b[R])==0)f1=1;
			}
			R--;
			ans+=mod-(pw[cnt]-1)*pw[R-P]%mod;
			if(ans>=mod)ans-=mod;
		}
		cout<<ans<<'\n';
	}
}

int main(){
	pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=pw[i-1]*2%mod;
	ios::sync_with_stdio(false);
	int T=1;
	cout<<fixed<<setprecision(15);
	//cin>>T;
	while(T--)solve();
}
