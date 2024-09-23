#include<bits/stdc++.h>
using namespace std;
#define D double
int main(){
	int R,X;
	scanf("%d%d",&R,&X);
	double r=cos((D)X/R)*R;
	D ans=(R/r-1)*X;
	cout<<std::fixed<<std::setprecision(10)<<ans<<endl;
	return 0;
}
