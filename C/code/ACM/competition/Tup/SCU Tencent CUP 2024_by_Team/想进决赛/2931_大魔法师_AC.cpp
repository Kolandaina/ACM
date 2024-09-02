#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e3;
int n,m[3],v[3][N+5],w[3][N+5],dp[3][N+5];

int main(){
	scanf("%d %d %d %d",&n,&m[0],&m[1],&m[2]);
	for (int k = 0; k < 3; k ++)
	  for (int i = 1; i <= m[k]; i ++)
	    scanf("%d %d",&v[k][i],&w[k][i]);

	for (int k = 0; k < 3; k ++)
	  for (int i = 1; i <= m[k]; i ++)
		for (int j = n; j >= v[k][i]; j --)
		  dp[k][j] = max(dp[k][j], dp[k][j-v[k][i]] + w[k][i]);
	long long ans = 0;
	for (int i = 0; i <= n; i ++)
		for (int j = 0; i + j <= n; j ++){
			int k = n - i - j;
			ans = max(ans, 1ll * dp[0][i] * dp[1][j] * dp[2][k]);
		}
	printf("%lld\n",ans);
	return 0;
}

