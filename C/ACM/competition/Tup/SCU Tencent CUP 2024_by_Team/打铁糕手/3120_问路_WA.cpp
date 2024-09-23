#include <bits/stdc++.h>

using namespace std;

/*

*/

int main(){
		
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int R,X;
	scanf("%d%d",&R,&X);
	if(!X){
		printf("%.15f",0.0);
	}else{
		double r = cos(X * 1.0 / R) * R;
		double Cr = 2 * acos(-1) * r;
		double x1 = X - floor(X * 1.0 / Cr) * Cr;
		double a = x1 > acos(-1) * r ? 2 * acos(-1) * r - x1 : x1;
		double res = a * R / r - X;
		printf("%.15f",res);
	}
	
	return 0;
}
