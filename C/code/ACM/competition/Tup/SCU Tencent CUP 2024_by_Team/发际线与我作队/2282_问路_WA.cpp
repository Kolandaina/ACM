#include<bits/stdc++.h>
using namespace std;
//const int N=1e5+5;
//int n,m;

void sovle(){
	int r,x;
	scanf("%d%d",&r,&x);
	double res = 1.0 * x * (1.0/cos(1.0 * x/r) - 1);
	printf("%.8lf", res);
}
int main(){
	sovle();
}
