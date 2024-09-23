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

int cnt;

int c(int n){
	if(n==0)return 0;
	if(n%2==1)return c(n-1)+1;
	else return c(n/2)+1;	
}

void solve(){
	n=read();
	if(c(n)%2==0)puts("Bob");
	else puts("Alice");
}

int main(){
	int t=read();
	while(t--)solve();
	return 0;
}
