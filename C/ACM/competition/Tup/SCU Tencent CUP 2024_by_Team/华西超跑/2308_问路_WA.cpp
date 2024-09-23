#include<bits/stdc++.h>
using namespace std;
#define D double
#define PIE 3.1415926536
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
