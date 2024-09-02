#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double s;
	double x, r;
	cin >> r >> x;
	s = x / r;
	double ans =fabs(x *(1-1/cos(s)));
	cout << ans << endl;
	return 0;
}