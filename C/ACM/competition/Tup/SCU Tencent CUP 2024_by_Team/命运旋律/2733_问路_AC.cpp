#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
const int mod = 1e9 + 7;
#define pi acos(-1)

void solve(){
	double R,x;
	cin>>R>>x;
	double si=x/R;
	double r=R*cos(si);
	double L=2*pi*R;
	double l=2*pi*r;
	double t=x;
	while(t>l) t-=l;
	if(t>pi){
		t=l-t;
		double y=t/cos(si);
		if(y+x>L/2) printf("%.10lf\n",L-(y+x));
		else printf("%.10lf\n",y+x);
	}
	else{
		double y=t/cos(si);
		printf("%.10lf\n",max(y-x,x-y));
	}
}
signed main(){
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
