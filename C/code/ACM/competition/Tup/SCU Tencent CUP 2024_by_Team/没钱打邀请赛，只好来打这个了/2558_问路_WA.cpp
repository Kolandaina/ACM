#include<bits/stdc++.h>
using namespace std;
const double PI=asin(1);
int main(){
	double r,x;
	cin>>r>>x;
	double d=r*cos(x/r);
	double res=x*(r/d-1.0);
	printf("%.10f",res);
	return 0;
}
