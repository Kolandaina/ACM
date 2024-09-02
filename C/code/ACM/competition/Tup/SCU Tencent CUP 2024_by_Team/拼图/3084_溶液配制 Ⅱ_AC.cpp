#include <bits/stdc++.h>
#define LL long long
#define ld long double
#define pdd pair<ld,ld>
using namespace std;
const LL N=5e6;
LL mod=1e9+7;
LL p2[N];
LL n,q;
vector<pdd> po;
map<pdd,int> M;
const ld eps=1e-10;
const ld PI=acos(-1);
struct P{
	pdd p;
	ld v;
	bool operator<(P o)const{
		return v<o.v;
	};
};
ld fang(ld a){
	return a*a;
}
bool check(pdd a,pdd b,const pdd& c){
	a.first-=c.first;
	a.second-=c.second;
	b.first-=c.first;
	b.second-=c.second;
	return a.first*b.second-a.second*b.first>0;
}
ld dis(const pdd& a,const pdd& b){
	ld res=fang(a.first-b.first)+fang(a.second-b.second);
	return sqrt(res);
}
ld calc(const pdd& a,const pdd& b){
	ld y=b.second-a.second;
	ld x=b.first-a.first;
	ld d=dis(a,b);
	y/=d,x/=d;
	ld ax=acos(x);
	if(y<0)ax=2*PI-ax;
	return ax;
}
int main() {
	//freopen("in.txt","r",stdin);
	p2[0]=1;
	for(LL i=1;i<N;i++)p2[i]=p2[i-1]*2%mod;
	cin>>n>>q;
	po.resize(n);
	for(auto& p:po)cin>>p.first>>p.second;
	for(auto& p:po)M[p]++;
	while(q--){
		ld x,y;
		cin>>x>>y;
		vector<P> vec;
		LL has=0;
		for(auto& p:po){
			if(p==make_pair(x,y)){
				has++;
			}else{
				vec.push_back({p,calc({x,y},p)});
			}
		}
		sort(vec.begin(),vec.end());
		int h=vec.size();
		for(int i=0;i<h;i++)vec.push_back(vec[i]);
		for(int i=h;i<2*h;i++)vec[i].v+=2*PI;
//		for(auto& pp:vec){
//			cout<<pp.p.first<<' '<<pp.p.second<<' '<<pp.v<<endl;
//		}
//check({vec[j+1].p.first,vec[j+1].p.second},{x,y},{vec[i].p.first,vec[i].p.second})
		int j=0;
		LL dec=0;
		for(int i=0;i<h;i++){
			ld gg=vec[i].v+PI;
			while((j+1<2*h)&&(vec[j+1].v<gg-eps))j++;
			dec+=p2[j-i];
			//cout<<"j-i: "<<j-i<<endl;
			dec%=mod;
		}
		LL nn=M[{x,y}];
		//cout<<nn<<endl;
		LL nw=n-nn;
		LL ans=p2[nw]-dec;
		ans%=mod;
		ans--;
		ans+=(p2[nn]-1)*p2[nw]%mod;
		ans%=mod;
		ans+=mod;
		ans%=mod;
		cout<<ans<<'\n';
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
/*
4 4
0 0
20 0
0 20
20 20
10 10
0 0
30 20.5
0.001 0
*/

