#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define push_back pb
const int N=2000013;
const ld pi=3.14159265358979323846264;
int f[N];

void solve(){
	ld r,x;
	cin>>r>>x;
	ld ang=(ld)x/r;
	ld q=x/2/pi/cosl(ang)/r;
	ld ans=x*(1/cosl(ang)-1);
	while(ans>pi*r)ans-=2*pi*r;
	while(ans<-pi*r)ans+=2*pi*r;
	cout<<abs(ans)<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	int T=1;
	cout<<fixed<<setprecision(15);
	//cin>>T;
	while(T--)solve();
}
