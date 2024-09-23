#include <iostream>
#include<cstdio>
using namespace std;

#define N 2020
#define int long long
int f1[N],f2[N],f3[N];
struct d {
	int v,w;
	void rd() {
		cin>>v>>w;
	}
	void print() {
		printf("[]%lld %lld\n",v,w);
	}
};
struct d mm1[N],mm2[N],mm3[N];
void init(int mi,d mmi[N]) {
	for(int i=1;i<=mi;++i) {
		mmi[i].rd();
//		mmi[i].print();
	}
	return;
}
void cal(int n,int mi,d mmi[N],int f[N]) {
	int i,j;
	int sum=0;
	for(i=1;i<=mi;++i) {
		sum+=mmi[i].v;
	}
	for(i=1;i<=n;++i) {
		f[i]=0;
	}
	for(i=1;i<=mi;++i) {
		for(j=n;j>=mmi[i].v;--j) {
			f[j]=max(f[j],f[j-mmi[i].v]+mmi[i].w);
		}
	}
//	for(i=1;i<=sum;++i) {
//		printf("i=%lld,f=%lld\n",i,f[i]);
//	}
	return;
}
signed main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	int n,m1,m2,m3;
	cin>>n>>m1>>m2>>m3;
	int i,j;
	init(m1,mm1);
	init(m2,mm2);
	init(m3,mm3);
	cal(n,m1,mm1,f1);
	cal(n,m2,mm2,f2);
	cal(n,m3,mm3,f3);
	int ans=0;
	for(i=1;i<=n;++i) {
		for(j=1;j<n-i;++j) {
			ans=max(ans,f1[i]*f2[j]*f3[n-i-j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}

