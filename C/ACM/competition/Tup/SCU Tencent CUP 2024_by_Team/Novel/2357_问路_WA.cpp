#include<bits/stdc++.h>
using namespace std;

double r, x;

int main(){
	scanf("%lf%lf", &r, &x);
	double temp = cos(x / r);
	temp = x / temp - x;
	printf("%.15lf\n", temp);
	return 0;
}
