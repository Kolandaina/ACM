#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=501010;
const ll inf=0x3f3f3f3f;
const ll p=1e9+7;
typedef double db;
const db pi = acos(-1);

db X,R;
db r;

int main() {
	cin>>R>>X;
	r = cos(X/R)*R;
//	cout<<r<<endl;
	db hu = X/r-X/R;
	while(hu>=2.0*pi) hu -= 2.0*pi;
	db fan = 2.0*pi-hu;
	hu = min(hu,fan);
	printf("%.12lf",hu*R);
	return 0;
}
/*

3 3
10.000
15.000
16.000
00.0
15.000
22.000

*/

