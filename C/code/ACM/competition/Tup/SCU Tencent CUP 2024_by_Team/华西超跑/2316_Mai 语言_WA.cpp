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
signed main(){
	std::ios::sync_with_stdio(0);
	int n,m,k;
	std::cin>>n>>m>>k;
	k-=n;
	if(m<=0||k<0){
		puts("-1");
		return 0;
	}
	std::vector<int>ans(n);
	for(int i=0,p=1;i<n;++i,p*=2){
		int x=(m-2-dig(p))/p-1;
		if(x<0){
			puts("-1");
			return 0;
		}
		if(x>k){
			ans[i]=k;
			k=0;
		}else{
			
		ans[i]=x;
		k-=x;
		}
	}
	for(int _=0,p=1;_<n;++_,p*=2){
		printf("{%d}",p);
		for(int i=0;i<ans[i]+1;++i){
			for(int j=0;j<p;++j){
				printf(",");
			}
		}
		puts("");
	}
}
