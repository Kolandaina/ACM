#include<bits/stdc++.h>
using namespace std;
const double PI=asin(1)*2.0;
int main(){
	double r,x;
	cin>>r>>x;
	double d=cos(x/r);
	double res=x*(1.0/d-1.0);
	while(res>=2.0*PI*r){
		res-=2.0*PI*r;
	}
	//cout<<res<<"\n";
//	cout<<abs(2.0*PI*r-res)<<"\n";
	res=min(res,abs(2.0*PI*r-res));
	printf("%.15f",res);
	return 0;
}
