#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'

#define ll long long
#define int ll
const int N = 5e6 + 10;
const int mod = 1e9 + 7;
const double pi = 3.14159265358979323846264;
void solve(){
	double R,x;
	cin>>R>>x;
	double r=R*abs(cos(x/R));
	double xita=(x/r);
	while(xita>2*pi){
		xita-=2*pi;
	}
	if(R*xita-x>pi*R) printf("%.10lf",(2*pi*R)-(R*xita-x));
	else printf("%.10lf",R*xita-x);
}
signed main(){
	int _ = 1;
	//cin >> _;
	for(int i = 1;i<=_;i++){
		solve();
	}
	return 0;
}
