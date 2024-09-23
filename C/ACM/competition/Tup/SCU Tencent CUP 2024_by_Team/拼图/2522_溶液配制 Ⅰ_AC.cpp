#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=1e6;
LL mod=1e9+7;
LL p[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	p[0]=1;
	for(int i=1;i<N;i++)p[i]=p[i-1]*2%mod;
	int n,q;
	cin>>n>>q;
	vector<double> A(n);
	for(auto& i:A)cin>>i;
	sort(A.begin(),A.end());
	while(q--){
		double x;
		cin>>x;
		if(x<A[0]||x>A.back()){
			cout<<0<<'\n';
			continue;
		}
		auto i1=(upper_bound(A.begin(),A.end(),x))-A.begin()-1;
		auto i2=(lower_bound(A.begin(),A.end(),x))-A.begin();
		LL nw=n;
		LL nn=0;
		if(i1>=i2){
			nn=i1-i2+1;
			nw-=nn;
		}
		LL ns=i2,nb=n-nn-ns;
				//cout<<nn<<' '<<nw<<' '<<ns<<' '<<nb<<endl;
		LL NN=p[nw]-p[ns]-p[nb]+1;
		NN%=mod;
		LL ans=NN+(p[nn]-1)*p[nw]%mod;
		ans=(ans%mod+mod)%mod;
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3 3
10 15 16
0 15 15.999
*/

