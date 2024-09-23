#include <bits/stdc++.h>
using namespace std;
typedef long double db;

const int N=4e6+7;
const int inf=0x3f3f3f3f;

inline int read() {
	int sum = 0, ff = 1; char c = getchar();
	while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
	while(c>='0'&&c<='9') { sum = sum * 10 + c -'0'; c = getchar(); }
	return sum * ff;
}

map <ll, int> f;
int n,m;
struct P{
	db x,y;
}a[N],O;
ll ans;
int du[N];

inline bool cmp(P A,P B) {
	P AO = (P){A.x-O.x, A.y-O.y};
	P BO = (P){B.x-O.x, B.y-O.y};
	if(AO=={0,0}) return 0;
	if(BO=={0,0}) return 1;
	return atan2(AO.y,AO.x) < atan2(BO.y,BO.x);
}

int main() {
	n = read(); m = read();
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y;
		int Aint = (int)(a[i].x*1000+0.5);
		int Bint = (int)(a[i].y*1000+0.5);
		f[Aint*1e6+Bint]++;
	}
	while(m--) {
		ans = 0;
		cin>>O.x>>O.y;
		int Aint = (int)(O.x*1000+0.5);
		int Bint = (int)(O.y*1000+0.5);
		if(f[Aint*1e6+Bint]) {
			ans += (ksm(2,f[Aint*1e6+Bint])-1) * (ksm(2,n-f[Aint*1e6+Bint])) %p;
		}
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++) cout<<"("<<a[i].x<<" , "<<a[i].y<<")\n";
	}
	return 0;
}
