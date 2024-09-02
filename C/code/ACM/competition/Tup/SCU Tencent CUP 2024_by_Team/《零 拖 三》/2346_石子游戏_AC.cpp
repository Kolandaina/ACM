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

#define rep(i,l,r) for(int i=l,l<=r;++i)
#define dep(i,r,l) for(int i=r;i>=l;--i)

int n;

const int MAX = 1e6 + 5;
bool cnt[MAX];

//int c(int n){
//	if(n==0)return 0;
//	if(n%2==1)return c(n-1)+1;
//	else return c(n/2)+1;	
//}
void init () {
	cnt[1] = true;
	cnt[2] = false;
	for (int i = 3 ; i <= MAX-1; ++i) {
		if (i % 2 != 0) {
			if (cnt[i-1] != 1) {
				cnt[i] = 1;
			} else cnt[i] = 0; 
		} else {
			if (!cnt[i-1] || !cnt[i/2]) {
				cnt [i]= 1;
			} else cnt[i] = 0;
		}
	}
}
void solve(){
	n=read();
	if (cnt[n] == 1) {
		puts("Alice");
	} else puts("Bob");
}

int main(){
	init();
	int t=read();
	while(t--)solve();
	return 0;
}
