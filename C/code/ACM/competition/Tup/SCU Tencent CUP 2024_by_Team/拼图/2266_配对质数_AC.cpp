#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
using namespace std;
const LL N=5e6+10;
bool has[N];
int cnt=0;
int p[N];
void init(){
	for(LL i=2;i<N;i++){
		if(!has[i])p[cnt++]=i;
		for(int j=0;j<cnt&&p[j]*i<N;j++){
			has[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
}
vector<pii> calc(LL v){
	vector<pii> res;
	if(v==0){
		return res;
	}
	if(v==2){
		for(int i=1;i<2;i++)res.push_back({i,3-i});
		return res;
	}
	if(v==4){
		for(int i=1;i<=2;i++)res.push_back({i,5-i});
		return res;
	}
	for(LL tr=v-1;tr;tr-=2){
		if(!has[tr+v]){
			auto rrs=calc(tr-1);
			for(LL h=tr;h<=(tr+v)/2;h++){
				rrs.push_back({h,v+tr-h});
			}
			return rrs;
		}
	}
}
void solve(){
	LL n;
	cin>>n;
	auto res=calc(n*2);
	for(auto i:res)cout<<i.first<<' '<<i.second<<'\n';
}
int main() {
	init();
	int _;
	cin>>_;
	while(_--)solve();
	return 0;
}
