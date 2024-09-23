#pragma GCC optimize("Ofast,inline,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=std::vector<int>;
using pii=std::pair<int,int>;
#define eb emplace_back
#define all(c) std::begin(c),std::end(c)

//std::vector<ll>a[3][2]={{{1},{2},},{{3,},},{},};
signed main(){
//	std::ofstream fout("test.txt");
	std::ios::sync_with_stdio(0);
	ll a=11,s=4,b,t;
//	std::cin>>a>>s;
	ll sums=0,maxs=0;
	for(ll a=0;a<=100;++a){
//			fout<<"{";
		if(a>=2) for(ll s=0;s<=100;++s)[&]{
			if(s<2){
//				fout<<"{},";
				return;
			}
			ll as=1;
			for(int i=0;i<s;++i){
				as*=a;
				if(as>ll(1e12)){
					return;
				}
			}
			ll l=1,r;
		//	std::cerr<<as<<'\n';
			std::vector<ll>vec;
			for(;l<=as;l=r+1){
				ll val=as/l;
				r=as/val;
				if(as%r==1){
					vec.eb(r);
				}
			}
			vec.eb(as-1);
			sums+=vec.size();
			maxs=std::max<ll>(maxs,vec.size());
//			fout<<"{";
//			for(auto&&x:st)fout<<x<<",";
//			fout<<"},";
//			std::cerr<<a<<' '<<s<<' '<<st.size()<<'\n';
		}();
//		fout<<"},";
	}
	std::cerr<<sums<<' '<<maxs<<'\n';
	
}
