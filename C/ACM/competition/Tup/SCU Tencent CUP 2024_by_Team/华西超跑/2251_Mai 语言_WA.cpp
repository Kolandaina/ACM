#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=std::vector<int>;
using pii=std::pair<int,int>;
#define eb emplace_back
#define all(c) std::begin(c),std::end(c)
signed main(){
	std::ios::sync_with_stdio(0);
	int n,m,k;
	std::cin>>n>>m>>k;
	k-=n;
	m-=3;
	if(m<=0||k<0){
		puts("-1");
		return 0;
	}
	std::vector<int>ans(n);
	for(int i=0,p=1;i<n;++i,p*=2){
		if(m<p){
			puts("-1");
			return 0;
		}
		int x=m/p-1;
		if(x>k){
			ans[i]=k;
			break;
		}
		ans[i]=x;
		k-=x;
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
