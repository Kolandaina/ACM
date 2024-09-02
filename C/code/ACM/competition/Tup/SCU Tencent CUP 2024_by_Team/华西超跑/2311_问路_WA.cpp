#include<bits/stdc++.h>
using namespace std;
#define D double
const double PIE=acos(-1.0);
int main(){
	int R,X;
	scanf("%d%d",&R,&X);
	double r=cos((D)X/R)*R;
	D the=X/r;
	int d=the/2/PIE;
	the-=d*2*PIE;
	if(the>PIE){
		the=2*PIE-the;
	}
	D ans=the*R-X;
	cout<<std::fixed<<std::setprecision(10)<<ans<<endl;
	return 0;
}
