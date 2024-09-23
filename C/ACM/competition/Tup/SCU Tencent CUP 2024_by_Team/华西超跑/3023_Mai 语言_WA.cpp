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
	if(k==1){
		for(int i=0,p=2;i<n;++i,p*=2){
			ll req=i==n-1?2:1;
			if(dig(p)+2+req>m){
				puts("-1");
				return 0;
			}
		}
		for(int i=0,p=2;i<n;++i,p*=2){
			printf("{%d}",p);
			for(int j=0;j<(i==n-1?2:1);++j){
					printf(",");
			}
			puts("");
		}
		return 0;
	}
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
//		std::cerr<<i<<' '<<p<<' '<<dig(p)<<' '<<x<<' '<<k<<'\n';
		if(x<0){
			puts("-1");
			return 0;
		}
		if(x*p2[n-1-i]>k){
			x=k/p2[n-1-i];
		}
		ans[i]=x;
//		std::cerr<<ans[i]<<'\n';
		k-=x*p2[n-1-i];
	}
	if(k!=0){
		puts("-1");
		return 0;
	}
	for(int _=0,p=1;_<n;++_,p*=2){
		printf("{%d}",p);
		for(int i=0;i<ans[_]+1;++i){
				printf(",");
		}
		puts("");
	}
}
