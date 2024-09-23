#include <bits/stdc++.h>

using namespace std;

int read(){
	int res=0,sign=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')sign=-sign;
	for(;'0'<=ch&&ch<='9';ch=getchar()){
		res=(res<<3)+(res<<1)+(ch^'0');
	}
	return res*sign;
}
#define pi acos(-1)
#define rep(i,l,r) for(int i=l,l<=r;++i)
#define dep(i,r,l) for(int i=r;i>=l;--i)
double cal(int x, int r) {
	if(x==0||r==0)return 0;
	double tmp = (double)x/(double)r;
	double res = (1 - cos(tmp)) / cos(tmp) * tmp;
	while(res>=2*pi)res-=2*pi;
	if(res>pi)res=2*pi-res;
	return res*r;
}
void solve(){
	int r = read(), x = read();
	printf("%.8lf", cal(x, r));	
}

int main(){
	int t=1;
	while(t--)solve();
	return 0;
}
