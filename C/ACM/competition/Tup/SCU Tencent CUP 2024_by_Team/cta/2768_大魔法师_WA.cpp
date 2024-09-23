#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
const int N = 2010;
ll dp[3][N];
int v[3][N], w[3][N];
int n, cnt[3];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d%d",&n, &cnt[0], &cnt[1], &cnt[2]);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < cnt[i]; j++) scanf("%d%d", &v[i][j], &w[i][j]); 
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < cnt[i]; j++){
			for(int k = 0; k <= n - v[i][j]; k++) dp[i][k+v[i][j]] = max(dp[i][k+v[i][j]], dp[i][k] + w[i][j]);
		}
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; i + j <= n; j++) ans = max(ans, dp[0][i] * dp[1][j] * dp[2][n-i-j]);
	}
	printf("%lld\n", ans);
	return 0;
}

