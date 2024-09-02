#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double R,x;
	cin>>R>>x;
	printf("%.7lf",(x/cos(x/R))-x);
	return 0;
}

