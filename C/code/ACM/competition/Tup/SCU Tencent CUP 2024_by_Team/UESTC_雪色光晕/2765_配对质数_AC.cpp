#include <bits/stdc++.h>
using namespace std;

const int N=4e6+7;
const int inf=0x3f3f3f3f;

inline int read() {
	int sum = 0, ff = 1; char c = getchar();
	while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
	while(c>='0'&&c<='9') { sum = sum * 10 + c -'0'; c = getchar(); }
	return sum * ff;
}

bool mk[N];
int p[N],cnt=0,R[N],tp=0;

int main() {
	int T=read();
	mk[1]=1;
	for(int i=2;i<N;i++){
		if(!mk[i])
			p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<N;j++){
			mk[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
	while(T--){
		int n=2*read();
		tp=0;
		while(n){
			int l=n-1;
			while(mk[l+n]) l--;
			R[++tp]=n;
			n=l-1;
		}
		R[tp+1]=0;
		for(int i=tp;i;i--){
			for(int j=0;R[i+1]+1+j<R[i]-j;j++)
				printf("%d %d\n",R[i+1]+1+j,R[i]-j);
		}
	}
}
