#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int R,X;
	scanf("%d%d",&R,&X);
	if(!X || !R){
		printf("%.15f",0.0);
	}else{
		double s = cos(X * 1.0 / R) * R*2*acos(-1);
		double S = R*2*acos(-1);
		double Y=X;
		if(X>s){
			Y-=(int)(X/s)*s;
		}
		Y/=cos(X * 1.0 / R);
		Y-=X;
		Y=fabs(Y);
		printf("%.15f",min(Y,S-Y));
		
		
	}
	
	return 0;
}
