#include<bits/stdc++.h>
using namespace std;
int n;
inline int read(){
	int r=0,f=1;char  c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return r*f;
}
inline string sread(){
	string s=" ";char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while(c<='z'&&c>='a')s+=c,c=getchar();
	return s;
}
int lowbit(int x){return x&(-x);}
const int N = 1e6+100;
bool dp[N];
signed main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	dp[0] = false;
	for(int i = 1; i <= 1e6+1; i++){
		if(i&1) dp[i] = dp[i-1] ^ 1;
		else dp[i] = min(dp[i-1], dp[i / 2]) ^ 1; 
	}
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		if(dp[n]) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}
