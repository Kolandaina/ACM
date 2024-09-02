#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ld long double
#define pdd pair<double,double>
using namespace std;
const double PI=acos(-1);
LL mod=998244353;
LL qpow(LL a,LL t){
	LL res=1;
	while(t){
		if(t&1)res*=a,res%=mod;
		a*=a,a%=mod;
		t>>=1;
	}
	return res;
}
double calc(double a,double b){
	a+=b*1e5;
	LL l=0,r=1e9;
	while(l<r){
		double m=(l+r+1)>>1;
		if(a-m*b>=0)l=m;
		else r=m-1;
	}
	return a-l*b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	double R,X;
	cin>>R>>X;
	double o=X/R;
	double r=R*cos(o);
	double a=X/r;
	LL l=0,rr=1e9;
	while(l<rr){
		LL m=(l+rr+1)>>1;
		if(a-m*PI*2>=0)l=m;
		else rr=m-1;
	}
	a-=l*PI*2;
	double ans=a*R;
	double dis=X;
	dis=calc(dis,2*PI*R);
	ans-=dis;
	cout<<fixed<<setprecision(10);
	cout<<abs(ans);
	
	return 0;
}
