#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int R,X;
	scanf("%d%d",&R,&X);
	if(!X || !R){
		printf("%.15f",0.0);
	}else{
		double r = cos(X * 1.0 / R) * R;
		double Cr = 2 * acos(-1) * r,CR = 2 * acos(-1) * R;
		double x1 = X - floor(X * 1.0 / Cr) * Cr;
		double a = x1 > Cr * 0.5 ? Cr - x1 : x1;
		double res = a * R / r - X;
		res=min(fabs(res),fabs(CR-fabs(res)));
		printf("%.15f",res);
	}
	
	return 0;
}
