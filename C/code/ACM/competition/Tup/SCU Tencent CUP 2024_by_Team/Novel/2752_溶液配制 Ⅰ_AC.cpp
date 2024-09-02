#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int n, q,mi[100005];
double w[100015], x;

signed main(){
	scanf("%d%d", &n, &q);
	mi[0] = 1;
	for(int i = 1;i<=100004;i++){
		mi[i] = mi[i-1]*2;
		mi[i]%=mod;
	}
	for(int i = 1; i <= n; i++){
		scanf("%lf", &w[i]);
	}
	sort(w + 1, w + 1 + n);
	while(q--){
		int ans = 0;
		scanf("%lf", &x);
		int pos = lower_bound(w + 1, w + 1 + n, x) - w;
		if(x == w[pos]){
			int temp = pos;
			int cnt = 0;
			while(x==w[pos]){
				ans+=mi[n-1-cnt];
				ans%=mod;
				pos++;
				cnt++;
			}
			if(temp!=n&&temp!=1){
				ans+=(mi[temp-1]-1)*(mi[n-pos+1]-1);
				ans%=mod;
			}
		}
		else{
			if(pos<=n&&pos!=1){
				ans+=(mi[pos-1]-1)*(mi[n-pos+1]-1);
				ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
