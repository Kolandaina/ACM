#include <bits/stdc++.h>
using namespace std;

const int N=2e3+7;
const int inf=0x3f3f3f3f;

inline int read() {
	int sum = 0, ff = 1; char c = getchar();
	while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
	while(c>='0'&&c<='9') { sum = sum * 10 + c -'0'; c = getchar(); }
	return sum * ff;
}

int count(int x){
	int ret=0;
	while(x) ret++,x/=10;
	return ret;
}

int a[30],f[30];

int main() {
	int n=read(),m=read(),K=read();
	for(int i=0;i<=25;i++)
		f[i]=count(1<<i);
	if(K==1){
		if(n==1){
			if(m>=4) printf("{1},");
			else printf("-1");
		}else{
			if(f[n]+4<=m){
				for(int i=1;i<=n;i++){
					printf("{%d},",1<<i);
					if(i!=n) printf("\n");
				}
				printf(",");
			}else printf("-1");
		}
	}else{
		int p=0;
		K-=2;
		for(int i=0;i<n;i++) a[i]=1;
		a[n-1]++;
		for(;p<n;p++){
			int ret=m-2-a[p]-f[p];
			if(ret<0){
				K=1<<30;
				break;
			}
			if(ret>=K){
				a[p]+=K;
				K=0;
				break;
			}else{
				K-=ret;
				a[p]+=ret;
				K<<=1;
			}
		}
		if(K) printf("-1");
		else{
			for(int i=0;i<n;i++){
				printf("{%d}",1<<i);
				for(int j=1;j<=a[i];j++)
					printf(",");
				printf("\n");
			}
		}
	}
	return 0;
}
