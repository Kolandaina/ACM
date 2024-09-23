#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=std::vector<int>;
using pii=std::pair<int,int>;
#define eb emplace_back
#define all(c) std::begin(c),std::end(c)
int dig(int x){
	int res=0;
	while(x){
		res++;
		x/=10;
	}
	return res;
}
int p2[24];
signed main(){
	std::ios::sync_with_stdio(0);
	ll n,m,k;
	std::cin>>n>>m>>k;
	for(int i=0,p=1;i<=n;++i,p*=2)p2[i]=p;
	k*=p2[n-1];
	k-=p2[n]-1;
	if(m<=0||k<0){
		puts("-1");
		return 0;
	}
	std::vector<int>ans(n);
	for(int i=0,p=1;i<n;++i,p*=2){
		ll x=m-2-dig(p)-1;
//		std::cerr<<i<<' '<<x<<' '<<k<<'\n';
		if(x<=0){
			puts("-1");
			return 0;
		}
		if(x*p2[n-1-i]>k){
			x=k/p2[n-1-i];
		}
		ans[i]=x;
		k-=x*p2[n-1-i];
	}
	if(k!=0){
		puts("-1");
		return 0;
	}
	for(int _=0,p=1;_<n;++_,p*=2){
		printf("{%d}",p);
//		std::cerr<<_<<' '<<ans[_]<<'\n';
		for(int i=0;i<ans[_]+1;++i){
				printf(",");
		}
		puts("");
	}
}
