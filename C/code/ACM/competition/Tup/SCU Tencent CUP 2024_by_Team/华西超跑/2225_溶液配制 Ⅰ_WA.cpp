#include<stdio.h>
#include<algorithm>
using namespace std;
#define P 998244353
int pw[100001];
double a[100000];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		pw[i]=(pw[i-1]*2+1)%P;
	}
	for(int i=0;i<n;i++){
		scanf("%lf",a+i);
	}
	sort(a,a+n);
	for(int i=0;i<q;i++){
		double x;
		scanf("%lf",&x);
		int ans=pw[n];
		int d=a+n-upper_bound(a,a+n,x);
		ans-=pw[d];
		d=lower_bound(a,a+n,x)-a;
		ans-=pw[d];
		ans=ans%P+P;
		printf("%d\n",ans%P);
	}
	return 0;
}
/*
3 3
10.0
15
16
0
15
15.999
*/
