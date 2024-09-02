#include <bits/stdc++.h>
using namespace std;

const int N=2e3+7;
const int inf=0x3f3f3f3f;

int T;

inline int read() {
	int sum = 0, ff = 1; char c = getchar();
	while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
	while(c>='0'&&c<='9') { sum = sum * 10 + c -'0'; c = getchar(); }
	return sum * ff;
}

int dp1[N],dp2[N],dp3[N];
long long F[N],G[N];

int main() {
	T = 1;
	while(T--) {
		int n=read(),m1=read(),m2=read(),m3=read();
		for(int i=1;i<=m1;i++){
			int v=read(),w=read();
			for(int j=n;j>=v;j--)
				dp1[j]=max(dp1[j],dp1[j-v]+w);
		}
		for(int i=1;i<=m2;i++){
			int v=read(),w=read();
			for(int j=n;j>=v;j--)
				dp2[j]=max(dp2[j],dp2[j-v]+w);
		}
		for(int i=1;i<=m3;i++){
			int v=read(),w=read();
			for(int j=n;j>=v;j--)
				dp3[j]=max(dp3[j],dp3[j-v]+w);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++) F[i]=max(F[i],1ll*dp1[j]*dp2[i-j]);
		long long Ans=0;
		for(int j=1;j<n;j++)
			Ans=max(Ans,1ll*F[j]*dp3[n-j]);
		cout<<Ans;
	}
	
	return 0;
}

/*
10 2 2 2
2 1
3 2
2 1
3 2
5 3
4 2
*/
